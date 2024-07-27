class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        for(int i=0;i<nums1.size();i++){
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            int index = distance(nums2.begin(), it) + 1;
            while(index < nums2.size()){
                if(nums1[i]<nums2[index]){
                    ans.push_back(nums2[index]);
                    break;
                }
                index++;
            }
            if(index == nums2.size()) ans.push_back(-1);
        } 
        return ans;
    }
};