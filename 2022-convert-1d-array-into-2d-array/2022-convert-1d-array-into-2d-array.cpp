class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector <vector<int>> res(m);
        int len = original.size();
        if(original.size()!= n*m) return {};
        for(int i=0;i<m;i++){
            res[i].assign(original.begin()+i*n,original.begin() + (i+1)*n);
        }
        return res;
    }
};