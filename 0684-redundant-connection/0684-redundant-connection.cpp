class Solution {
public:
    int find(vector<int>&parent,int u){
        if(u!=parent[u]){
            parent[u] = find(parent,parent[u]);
        }
        return parent[u];
    }
    bool unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        int pu = find(parent,u);
        int pv = find(parent,v);
        if(pu==pv)return false;
        if(rank[pu]>rank[pv]){
            parent[pv] = pu;
        }else if(rank[pv]>rank[pu]){
            parent[pu] = pv;
        }else{
            parent[pu] = pv;
            rank[pv]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n+1,0);
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++)parent[i] = i;
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            if(!unionSet(u,v,parent,rank)){
                return edge;
            }
        }
        return {};
    }
};