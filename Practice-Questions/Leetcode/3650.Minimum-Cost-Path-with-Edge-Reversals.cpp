class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n), radj(n);
        for(auto &e : edges) 
        {
            adj[e[0]].push_back({e[1], e[2]});
            radj[e[1]].push_back({e[0], e[2]});
        }
        const long long INF = 1e18;
        vector<vector<long long>> dist(n, vector<long long>(2, INF));
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) 
        {
            auto [cost, u, used] = pq.top(); pq.pop();
            if (cost > dist[u][used]) continue;

            for (auto [v, w] : adj[u]) 
            {
                if (dist[v][0] > cost + w) 
                {
                    dist[v][0] = cost + w;
                    pq.push({dist[v][0], v, 0});
                }
            }

            if (used == 0) 
            {
                for (auto [v, w] : radj[u]) 
                {
                    if (dist[v][0] > cost + 2LL * w) 
                    {
                        dist[v][0] = cost + 2LL * w;
                        pq.push({dist[v][0], v, 0});
                    }
                }
            }
        }

        long long ans = min(dist[n-1][0], dist[n-1][1]);
        return ans == INF ? -1 : ans;
    }
};
