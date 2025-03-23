typedef long long ll;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ll mod = 1e9 + 7;
        vector<vector<pair<int, int>>> g(n);
        for (auto &x: roads) {
            g[x[0]].push_back({x[1], x[2]});
            g[x[1]].push_back({x[0], x[2]});
        }

        vector<pair<ll, ll>> f(n, {0, LLONG_MAX});
        vector<bool> visited(n, false);
        f[0] = {1, 0};
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [time, idx] = pq.top();
            pq.pop();
            if (visited[idx]) continue;
            visited[idx] = true;
            for (auto &next: g[idx]) {
                auto [nextIdx, nextTime] = next;
                if (f[nextIdx].second > time + nextTime) {
                    f[nextIdx] = {f[idx].first, time + nextTime};
                    pq.push({time + nextTime, nextIdx});
                } else if (f[nextIdx].second == time + nextTime) {
                    f[nextIdx].first += f[idx].first;
                }
                f[nextIdx].first %= mod;
            }
        }
        return f[n - 1].first;
    }
};