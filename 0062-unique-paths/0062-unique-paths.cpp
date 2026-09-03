class Solution {
public:
    vector<vector<int>> memo;
    int dfs(int m,int n,int i,int j){
        if(i >=m || j>=n){
            return 0;
        }
        if(memo[i][j]!=-1)return memo[i][j];
        if(i==m-1 && j == n-1){
            memo[i][j] = 1;
        }
        else memo[i][j] = dfs(m,n,i+1,j)+ dfs(m,n,i,j+1);
        return memo[i][j];
    }
    int uniquePaths(int m, int n) {
        memo.assign(m,vector<int>(n,-1));
        return dfs(m,n,0,0);
    }
};