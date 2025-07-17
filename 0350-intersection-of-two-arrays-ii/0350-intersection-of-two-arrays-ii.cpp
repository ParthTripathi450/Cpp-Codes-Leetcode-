class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int count=0;
        vector<int> res;
        for(int i=0;i<nums2.size();i++){
            auto it = find(nums1.begin(), nums1.end(), nums2[i]);
            if(it!=nums1.end()){
                res.push_back(nums2[i]);
                count++;
                if(count==nums2.size())return res;
                nums1.erase(it);
            }
        }
        return res;
    }
};