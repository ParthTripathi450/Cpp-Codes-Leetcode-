class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target) return true;
            if(nums[l]==nums[m] && nums[r]==nums[m] ){
                l++;
                r--;
                continue;
            }
            //left sorted
            if(nums[l]<=nums[m]){
                if(nums[l]<=target && nums[m]>=target){
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            //right sorted
            else{
                if(nums[m]<=target && nums[r]>=target){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
        }
        return false;
    }
};