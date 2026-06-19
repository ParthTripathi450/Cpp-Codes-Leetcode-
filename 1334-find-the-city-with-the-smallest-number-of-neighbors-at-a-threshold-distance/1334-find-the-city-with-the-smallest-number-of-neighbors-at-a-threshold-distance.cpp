class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for(int i = 0; i < n; i++)
            dist[i][i] = 0;

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j],
                                     dist[i][via] + dist[via][j]);
                }
            }
        }

        int ans = -1;
        int minCount = INT_MAX;

        for(int city = 0; city < n; city++){

            int cnt = 0;

            for(int adjCity = 0; adjCity < n; adjCity++){
                if(dist[city][adjCity] <= distanceThreshold)
                    cnt++;
            }

            if(cnt <= minCount){
                minCount = cnt;
                ans = city;
            }
        }
        return ans;
    }
};