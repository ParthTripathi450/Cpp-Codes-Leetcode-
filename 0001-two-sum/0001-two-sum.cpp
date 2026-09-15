class Solution {
public:
//
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;//{num,i}
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int req = target - nums[i];
            if(mpp.find(req)!=mpp.end()){
                ans.push_back(i);
                return {i,mpp[req]};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};