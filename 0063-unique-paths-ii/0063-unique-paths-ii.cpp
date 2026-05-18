class Solution {
public:
    int dfs(vector<vector<int>>& obstacleGrid,vector<vector<int>>& memo,int m,int n){
        if(m>obstacleGrid.size()-1 || n> obstacleGrid[0].size()-1 || obstacleGrid[m][n]==1)return 0;
        if(memo[m][n]!=-1)return memo[m][n];
        if(m == obstacleGrid.size()-1 && n == obstacleGrid[0].size()-1)return 1;

        int bottom = dfs(obstacleGrid,memo,m+1,n);
        int right = dfs(obstacleGrid,memo,m,n+1);
        memo[m][n] = bottom+right;
        return memo[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return dfs(obstacleGrid,dp,0,0);
    }
};