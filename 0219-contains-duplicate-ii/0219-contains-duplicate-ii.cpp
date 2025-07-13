class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> arr;
        for(int i=0;i<nums.size();i++){
            arr[nums[i]].push_back(i);
        }
        for(auto& pair: arr){
            if(pair.second.size()>1){
                for(int i=1;i<pair.second.size();i++){
                    if(pair.second[i]-pair.second[i-1]<=k)return true;
                }
            }
        }
        return false;
    }
};