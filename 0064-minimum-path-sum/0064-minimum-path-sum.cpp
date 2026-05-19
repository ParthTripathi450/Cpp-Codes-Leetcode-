class Solution {
public:
    int dfs(vector<vector<int>>& grid,int m,int n,vector<vector<int>>&dp){
        if(m >= grid.size() || n>=grid[0].size())return INT_MAX;
        if(dp[m][n]!=-1)return dp[m][n];
        if(m == grid.size()-1 && n == grid[0].size()-1)return grid[m][n];
        int right = dfs(grid,m,n+1,dp);
        int bottom = dfs(grid,m+1,n,dp);
        dp[m][n] = grid[m][n] + min(right,bottom);
        return dp[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = grid[0][0];
        
        //first col
        for(int i=1;i<grid.size();i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        
        //fitst row
        for(int j=1;j<grid[0].size();j++){
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }



        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int left = dp[i][j-1];
                int bottom = dp[i-1][j];
                dp[i][j] = grid[i][j] + min(left,bottom);
            }
        }
        return dp[m-1][n-1];
    }
};