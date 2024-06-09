class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> v;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==target){
                v.push_back(i);
            }
            i++;
        }
        if(v.empty()){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        else if(v.size()==1){
            v.push_back(v[0]);
            return v;
        }
        else if(v.size()>2){
            vector <int> v2;
            v2.push_back(v[0]);
            v2.push_back(v[v.size()-1]);
            return v2;
        }
        else{
            return v;
        }
    }
};