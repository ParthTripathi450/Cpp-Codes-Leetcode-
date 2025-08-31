class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<vector<int>> graph,int node,int dst){
        path.push_back(node);
        if(node==dst){
            ans.push_back(path);
        }else{
            for(auto&nei:graph[node]){
                dfs(graph,nei,dst);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        dfs(graph,0,n-1);
        return ans;
    }
};