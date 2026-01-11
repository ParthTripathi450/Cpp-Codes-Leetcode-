class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int ans =INT_MIN;
        for(int num: nums){
            if(curr<0){
                curr=0;
            }
            curr+=num;
            if(curr>ans){
                ans = curr;
            }
        }
        return ans;
    }
};