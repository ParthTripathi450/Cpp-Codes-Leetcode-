class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>graph(n+1);

        for(auto &p: paths){
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        
        vector<int> res(n+1,0);

        for(int i=1;i<=n;i++){
            vector<bool> used(n+1);
            for(int nei:graph[i]){
                if(res[nei]!=0){
                    used[res[nei]] = true;
                }
            }

            for(int f=1;f<=4;f++){
                if(!used[f]){
                    res[i] = f;
                    break;
                }
            }
        }
        res.erase(res.begin());
        return res;
    }
};