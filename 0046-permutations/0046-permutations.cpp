class Solution {
public:
    void func(int start,vector<int>& nums,vector<vector<int>>& res){
        if(start == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[i],nums[start]);
            func(start+1,nums,res);
            swap(nums[i],nums[start]);
        }
    } 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        //vector<int> set;
        func(0,nums,res);
        return res;

    }
};