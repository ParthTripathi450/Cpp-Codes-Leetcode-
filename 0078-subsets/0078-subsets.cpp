class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> A,vector<int> temp,int i){
        if(i==A.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(A[i]);
        helper(A,temp,i+1);
        temp.pop_back();
        helper(A,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        helper(nums,temp,0);
        return ans;

    }
};