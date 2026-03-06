class Solution {
public:
    long long fuel;
    long long dfs(int node,int parent,vector<vector<int>>& adj,int seats){
        long long reps = 1;
        for(int nei:adj[node]){
            if(parent == nei)continue;
            reps += dfs(nei,node,adj,seats);
        }
        if(node!=0){
            fuel += (seats+reps-1)/seats; 
        }
        return reps;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<vector<int>> adj(n);
        for(auto &r: roads){
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        dfs(0,-1,adj,seats);
        return fuel;
    }
};