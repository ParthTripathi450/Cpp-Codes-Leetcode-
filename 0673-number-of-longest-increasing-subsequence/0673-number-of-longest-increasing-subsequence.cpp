class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> v(nums.size(), 1);
        vector<int> count(nums.size(),1);
        int max_num=0;
        for(int i=0;i<nums.size();i++){
            int j=0;
            while(j<i){
                if(nums[j]<nums[i]){
                    if(v[j]+1>v[i]){
                        v[i] = v[j]+1;
                        count[i] = count[j];
                    }
                    else if(v[i] == v[j]+1){
                        count[i]+=count[j];
                    }
                }
                j++;
            }
            max_num = max(v[i],max_num);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(v[i] == max_num){
                ans+=count[i];
            }
        }
        return ans;
    }

};