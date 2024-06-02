class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=nums.size()-(k%nums.size());
        int temp[k];
        for(int i=0;i<k;i++){
            temp[i]=nums[i];
        }
        for(int i=0;i<nums.size()-k;i++){
            nums[i]=nums[k+i];
        }
        int j=0;
        for(int i=nums.size()-k;i<nums.size();i++){
            nums[i]=temp[j];
            j++;
        }
    }
};