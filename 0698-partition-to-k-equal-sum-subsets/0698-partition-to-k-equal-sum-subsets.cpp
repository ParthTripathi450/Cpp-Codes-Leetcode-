class Solution {
public:
    bool dfs(int idx,vector<int>& nums, vector<int>& bucket,int target){
        if(idx == nums.size())return true;
        for(int i=0;i<bucket.size();i++){
            if(bucket[i] + nums[idx] > target)continue;
            bucket[i] += nums[idx];
            if(dfs(idx+1,nums,bucket,target))return true;
            bucket[i]-=nums[idx];
            if(bucket[i] == 0)break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=0;
        for(int x:nums) total+=x;
        if(total%k != 0)return false;
        int target = total/k;
        sort(nums.rbegin(),nums.rend());
        if(nums[0] > target) return false;
        vector<int> bucket(k,0);
        return dfs(0,nums,bucket,target);

    }
};