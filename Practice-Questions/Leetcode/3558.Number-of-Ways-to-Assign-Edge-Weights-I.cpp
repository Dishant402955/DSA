class Solution {
public:
    const int MOD = 1e9 + 7;

    int func(int pos, int currSumIsOdd, int depth,
             vector<vector<int>>& dp) {

        if (pos == depth)
            return dp[pos][currSumIsOdd] = 1 - currSumIsOdd;

        if (dp[pos][currSumIsOdd] != -1)
            return dp[pos][currSumIsOdd];

        long long curWays = 0;

        // Assign weight 1 -> parity flips
        curWays += func(pos + 1, 1 - currSumIsOdd, depth, dp);

        // Assign weight 2 -> parity remains same
        curWays += func(pos + 1, currSumIsOdd, depth, dp);

        return dp[pos][currSumIsOdd] = curWays % MOD;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n + 1, 0);
        queue<int> q;

        q.push(1);
        vis[1] = 1;

        int depth = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
            depth++;
        }

        depth--;

        vector<vector<int>> dp(depth + 1, vector<int>(2, -1));

        long long ans = 0;
        ans += func(0, 0, depth - 1, dp);
        ans += func(0, 1, depth - 1, dp);

        return ans % MOD;
    }
};
