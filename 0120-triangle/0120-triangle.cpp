class Solution {
public:
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& triangle,int m,int n){

        if(m==triangle.size()-1)return triangle[m][n];

        if(dp[m][n]!= -1)return dp[m][n];

        int bottom=triangle[m][n] + dfs(triangle,m+1,n);
        int diag=triangle[m][n] + dfs(triangle,m+1,n+1);

        return dp[m][n]=min(bottom,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,dg);
            }
        }
        return dp[0][0];
    }
};