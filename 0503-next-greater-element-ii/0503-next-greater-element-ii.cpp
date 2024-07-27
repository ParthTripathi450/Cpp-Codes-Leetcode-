class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector <int> vec;
        for(int i=0;i<nums.size();i++){
            int r=i+1;
            while(r%nums.size()!=i){
                if(nums[r%nums.size()]>nums[i]){
                    vec.emplace_back(nums[r%nums.size()]);
                    break;
                }
                r++;
            }
            if(r%nums.size()==i){
                vec.emplace_back(-1);
            }
        }
        return vec;   
    }
};