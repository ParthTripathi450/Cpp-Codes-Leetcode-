class Solution {
public:
    bool dfs(int node, int color, vector<int>& colors,vector<vector<int>>& graph){
        colors[node] = color;
        for(int nei:graph[node]){
            if(colors[nei] == color){
                return false;
            }
            if(colors[nei] == 0 && !dfs(nei,-color,colors,graph)){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,0);
        for(int i=0;i<n;i++){
            if(colors[i] == 0){
                if(!dfs(i,1,colors,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};