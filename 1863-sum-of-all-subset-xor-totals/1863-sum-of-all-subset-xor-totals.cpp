class Solution {
public:
    int ans=0;
    void dfs(vector<int>& nums,int idx,int currentXor){
        if(idx == nums.size()){
            ans+=currentXor;
            return ;
        }
        dfs(nums,idx+1,currentXor);
        dfs(nums,idx+1,currentXor^nums[idx]);
    }
    int subsetXORSum(vector<int>& nums) {
        dfs(nums,0,0);
        return ans;
    }
};