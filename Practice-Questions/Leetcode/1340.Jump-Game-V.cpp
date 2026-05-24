class Solution {
public:
    int maxJumps(vector<int>& a, int d) {
      int n = a.size();
      vector<vector<int>> adj(n, vector<int>());

      for (int i = 0; i < n; ++i) {
        int maxx = -1;
        for (int j = i - 1; j >= max(0, i - d); --j) {
          maxx = max(maxx, a[j]);
          if (maxx >= a[i]) break;
          adj[i].push_back(j);
        }

        maxx = -1;
        for (int j = i + 1; j <= min(n - 1, i + d); ++j) {
          maxx = max(maxx, a[j]);
          if (maxx >= a[i]) break;
          adj[i].push_back(j);
        }
      }

      vector<int> dist(n);

      auto dfs = [&](auto&& dfs, int x) -> void {
        if (dist[x] != 0) return;

        for (int& v : adj[x]) dfs(dfs, v);

        int maxx = 0;
        for (int& v : adj[x]) maxx = max(maxx, dist[v]);

        dist[x] = maxx + 1;
      };

      for (int i = 0; i < n; ++i) dfs(dfs, i);

      return *max_element(dist.begin(), dist.end());
    }
};
