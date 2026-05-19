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
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1) );
        return dfs(grid,0,0,dp);
    }
};