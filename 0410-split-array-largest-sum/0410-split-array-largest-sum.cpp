class Solution {
public:
    int funt(vector<int>& arr, int cap){
        int load=0;
        int store=1;
        for(int j = 0; j < arr.size(); j++){
            if(load+arr[j]<=cap){
                load+=arr[j];
            }
            else{
                load=arr[j];
                store++;
            }
        }
        return store;
    }

    int splitArray(vector<int>& nums, int k) {
        int max=*max_element(nums.begin(),nums.end());
        int sum=accumulate(nums.begin(),nums.end(),0);
        int low=max;
        int high=sum;
        while(low<=high)
        {
            int mid=(high+low)/2;
            int stdrq=funt(nums,mid);
            if(stdrq>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};