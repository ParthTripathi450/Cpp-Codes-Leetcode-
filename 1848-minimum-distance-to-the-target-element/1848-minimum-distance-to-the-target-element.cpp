class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int left=start,right=start; 
        int n=nums.size();
        
        while(left>=0 || right<n) 
        {
            if(nums[left]==target) 
            return abs(left-start);
            else if(nums[right]==target) 
            return abs(right-start);
            if(left>0) 
            left--;
            if(right<n-1) 
            right++;
        }
        return 0;
    }
};