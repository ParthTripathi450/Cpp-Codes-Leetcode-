class Solution {
public:
    void dfs(int i, int n,vector<int>& result){
        if(i>n)return;
        result.push_back(i);
        for(int j=0;j<=9;j++){
            int curr = (i*10)+j;
            if(curr>n)return;
            dfs(curr,n,result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>result;
        for(int i=1;i<=9;i++){
            dfs(i,n,result);
        }
        return result;
    }
};