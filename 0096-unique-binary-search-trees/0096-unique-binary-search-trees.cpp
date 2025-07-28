class Solution {
public:
    int numTrees(int n) {

        vector <int> dp(n+1,0);
        dp[0] = 1;
        for(int nodes=1;nodes<=n;++nodes){
            for(int root=1;root<=nodes;root++){
                dp[nodes] += dp[root-1] * dp[nodes-root];
            }
       }
       return dp[n];
    }
};