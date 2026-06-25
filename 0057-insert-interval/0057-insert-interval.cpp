class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ins, vector<int>& ne) {
        vector<vector<int>>res;
        int i=0, n=ins.size();
        while(i<n && ins[i][1]<ne[0]){
            res.push_back(ins[i]);
            i+=1;
        }
        while(i<n && ins[i][0]<=ne[1]){
            ne[0]=min(ne[0],ins[i][0]);
            ne[1]=max(ne[1],ins[i][1]);
            i+=1;
        }
        res.push_back(ne);
        while(i<n){
            res.push_back(ins[i]);
            i+=1;
        }
        return res;
    }
};