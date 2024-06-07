class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        for (int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int min=ind+1;
        for(int j=ind+1;j<nums.size();j++){
            if(nums[j]>nums[ind]&&nums[j]<nums[min]){
                min=j;
            }
        }
        int temp=nums[ind];
        nums[ind]=nums[min];
        nums[min]=temp;
        sort(nums.begin()+ind+1,nums.end());
    }
};