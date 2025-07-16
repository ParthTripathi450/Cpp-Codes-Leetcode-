class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int maxlen1=0;
        int maxlen2=0;
        int maxlen3=1;
        int maxlen4=1;
        //Case1:
        for(int num:nums){
            if(num%2==0)maxlen1++;
            else{
                maxlen2++;
            }
        }
        //Case3
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]%2 != nums[i]%2){
                maxlen3++;
            }
        }
        return max({maxlen1,maxlen2,maxlen3});
    }
};