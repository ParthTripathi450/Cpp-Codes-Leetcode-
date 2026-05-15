class Solution {
public:
    int func(vector<int> &nums,vector<int> &dp,int index){
        if(index == 0)return nums[index];
        if(index < 0)return 0;
        if(dp[index]!=-1) return dp[index];
        int take = nums[index]+func(nums,dp,index-2);
        int nottake = 0 + func(nums,dp,index-1);
        dp[index]=max(take,nottake);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        dp[0] = nums[0];
        return func(nums,dp,nums.size()-1);
    }
};