class Solution {
public:
    void backtrack(int row,int n,vector<vector<string>> &result,vector<bool> &cols,vector<string> &board,vector<bool>&diag1,vector<bool>&diag2){
        if(n==row){
            result.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(cols[col]||diag1[row-col+n-1]||diag2[row+col])continue;
            board[row][col] = 'Q';
            cols[col] = diag1[row-col+n-1] = diag2[row+col] = true;
            backtrack(row+1,n,result,cols,board,diag1,diag2) ;
            board[row][col] = '.';
            cols[col] = diag1[row-col+n-1] = diag2[row+col] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n,string(n,'.'));
        vector<bool> cols(n,false);
        vector<bool> diag1(2*n-1,false);
        vector<bool> diag2(2*n-1,false);
        backtrack(0,n,result,cols,board,diag1,diag2);
        return result;
    }
};