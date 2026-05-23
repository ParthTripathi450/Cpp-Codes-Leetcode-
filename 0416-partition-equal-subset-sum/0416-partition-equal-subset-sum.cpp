class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }

        if(sum%2)return false;

        int target = sum/2;
        int n = nums.size();

        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));

        for(int i=0;i<=n;i++){
            dp[i][0] = true;
        }

        for(int i=n-1;i>=0;i--){
            for(int t=1;t<=target;t++){

                bool take = false;

                if(nums[i]<=t){
                    take = dp[i+1][t-nums[i]];
                }

                bool notTake = dp[i+1][t];
                dp[i][t] = take || notTake;
            }
        }
        return dp[0][target];
    }
};