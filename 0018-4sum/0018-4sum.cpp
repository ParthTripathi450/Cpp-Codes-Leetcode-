class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            for(int j=nums.size()-1;j>2;j--){
                if(j<nums.size()-1 && nums[j+1]==nums[j]) continue;
                int k=i+1;
                int l=j-1;
                while(l>k){
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];
                    if(sum>target){
                        l--;
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        vector <int> temp = {nums[i],nums[k],nums[l],nums[j]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k-1]==nums[k])k++;
                        while(k<l && nums[l+1]==nums[l])l--;
                    }
                }
            }
        }
        return ans;
    }
};