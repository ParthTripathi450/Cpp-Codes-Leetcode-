class Solution {
public:
    int solve(vector<int>& nums, int k){
        int l=0,r=0,count=0,cnt=0;
        while(r<nums.size()){
            if(nums[r]%2 != 0){
                count++;
            }
            while(count>k){
                if(nums[l]%2 != 0){
                    count --;
                }
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};