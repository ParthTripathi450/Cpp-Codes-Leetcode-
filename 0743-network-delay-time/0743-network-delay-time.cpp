class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
        }

        vector<int> dist(n+1,INT_MAX);
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>
        >pq;

        dist[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [time,node] = pq.top();
            pq.pop();
            for(auto &it:adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                if(time + edgeWt < dist[adjNode]){
                    dist[adjNode] = time + edgeWt;
                    pq.push({
                        dist[adjNode],
                        adjNode
                    });
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX)return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};