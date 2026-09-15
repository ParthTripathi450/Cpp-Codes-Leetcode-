class Solution {
public:
    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int ROWS;
    int COLS;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=ROWS ||j<0 || j>=COLS || grid[i][j] == '0' )return;
        grid[i][j] = '0';
        for(int k=0;k<4;k++){
            dfs(grid,i +dir[k][0],j + dir[k][1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        ROWS = grid.size();
        COLS = grid[0].size();
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};