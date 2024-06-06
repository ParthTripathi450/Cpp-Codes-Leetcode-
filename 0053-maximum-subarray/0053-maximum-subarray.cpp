class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max1=INT_MIN;
        int crnmax=0;
        for(int i=0;i<nums.size();i++){
            crnmax+=nums[i];
            max1=max(max1,crnmax);
            if(crnmax<0){
                crnmax=0;
            }
        }
        return max1;
    }
};