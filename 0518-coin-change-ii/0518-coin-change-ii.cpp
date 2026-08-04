class Solution {
public:
    int dfs(int amount,vector<int>& coins,int i,vector<vector<int>>& dp){
        if(amount==0)return 1;
        if(amount<0)return 0;
        if(i>=coins.size())return 0;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int notTake = dfs(amount,coins,i+1,dp);
        int take=0;
        if(amount>=coins[i]){
            take = dfs(amount-coins[i],coins,i,dp);
        }
        return dp[i][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        //vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return dfs(amount,coins,0,dp);
    }
};