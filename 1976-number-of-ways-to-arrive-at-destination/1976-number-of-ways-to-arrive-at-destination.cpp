class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long INF = 1e18;
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);

        for(auto &r: roads){
            int u = r[0], v = r[1], t = r[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

        vector<long long > dist(n, INF);
        vector<long long> ways(n,0);
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

        while(!pq.empty()){
            auto[d,u] = pq.top();
            pq.pop();
            if(d>dist[u])continue;
            for(auto &[v,w]: adj[u]){
                long long nd = d + w;

                if(nd < dist[v]){
                    dist[v] = nd;
                    ways[v] = ways[u];
                    pq.push({nd,v});
                }
                else if(nd == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};