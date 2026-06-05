class Solution {
public:
    int solve(int ind,int target,vector<int>& nums){
        if(ind == 0){
            if(nums[0] == 0 && target == 0)return 2;
            if(nums[0] == target || nums[0] == -target)return 1;
            return 0;
        }
        int plus = solve(ind-1,target + nums[ind],nums);
        int minus = solve(ind-1,target - nums[ind],nums);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums.size()-1,target,nums);
    }
};