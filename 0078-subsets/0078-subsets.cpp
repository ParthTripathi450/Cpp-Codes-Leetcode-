class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        for(int i=0 ; i< (1<<nums.size());i++){
            vector<int> temp;
            for(int j=0;j<nums.size();j++){
                if(i & 1<<j) temp.push_back(nums[j]);
            }
            vec.push_back(temp);
        }
        return vec;
    }
};