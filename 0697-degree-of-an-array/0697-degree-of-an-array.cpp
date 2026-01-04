class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        struct Data {
            int count = 0;
            int firstIdx =-1;
            int lastIdx =-1;
        };

        unordered_map<int, Data> mp;
        int n = nums.size();
        int maxDeg =0;

        for (int i=0; i<n; i++) {
            if (!mp.count(nums[i])) mp[nums[i]].firstIdx = i; 
            mp[nums[i]].lastIdx = i; 
            maxDeg = max(maxDeg, ++mp[nums[i]].count); 
        }
        
        int res = n;
        for (const auto &[num, data]:mp){
            if (data.count==maxDeg) {
                res = min(res,data.lastIdx-data.firstIdx + 1); 
            }
        }

        return res;
    }
};