class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,zero=0;
        int len=0,maxlen=0;
        while(r<nums.size()){
            if (nums[r]==1){
                maxlen=max(maxlen,r-l+1);
                r++;
            }
            else if(nums[r]==0 && zero<k){
                zero++;
                maxlen=max(maxlen,r-l+1);
                r++;
            }
            else{
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
        }
        return maxlen;
    }
};