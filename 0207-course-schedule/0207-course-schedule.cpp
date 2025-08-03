class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& pre : prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }
        vector<int> state(numCourses, 0);

        for(int i=0; i<numCourses; ++i){
            if(hasCycle(graph,state, i)){
                return false;
            }
        }
        return true;
    }
    bool hasCycle(vector<vector<int>>& graph, vector<int>& state, int node){
        if(state[node] == 1)return true;
        if(state[node] == 2)return false;

        state[node] = 1;

        for(int neighbor : graph[node]){
            if(hasCycle(graph, state, neighbor)) return true;
        }
        state[node] = 2;
        return false;
    }
};