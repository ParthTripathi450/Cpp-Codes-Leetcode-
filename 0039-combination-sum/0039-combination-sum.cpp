class Solution {
public:
    void dfs(vector<int>& candidates,int target,int i,vector<vector<int>>& ans,vector<int>& arr){
        if(i == candidates.size())return;
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        else if(target<0) return ;
        if(target>=candidates[i]){
            arr.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i,ans,arr);
            arr.pop_back();
        }
        dfs(candidates,target,i+1,ans,arr);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        dfs(candidates,target,0,ans,arr);
        return ans;
    }
};