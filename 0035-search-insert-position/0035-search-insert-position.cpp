class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target>nums[nums.size()-1]){
            return nums.size();
        }
        else if(target<nums[0]){
            return 0;
        }
        int l=0;
        int r=nums.size()-1;
        while(l!=r){
            if(nums[l]<target){
                l++;
            }
            else if(nums[r]>target){
                r--;
            }
        }
        return l;   
    }
};