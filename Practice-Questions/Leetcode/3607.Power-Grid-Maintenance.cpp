class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        // Step 1: Build connected components using DSU
        for (auto& e : connections)
            dsu.unite(e[0], e[1]);

        // Step 2: Initialize online sets
        unordered_map<int, set<int>> compOnline;
        vector<bool> online(c + 1, true);

        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            compOnline[root].insert(i);
        }

        vector<int> res;

        // Step 3: Process queries
        for (auto& q : queries) {
            int type = q[0];
            int x = q[1];
            int root = dsu.find(x);

            if (type == 2) {
                // Go offline
                if (online[x]) {
                    online[x] = false;
                    compOnline[root].erase(x);
                }
            } else {
                // Maintenance check
                if (online[x]) {
                    res.push_back(x);
                } else {
                    auto& s = compOnline[root];
                    if (s.empty()) res.push_back(-1);
                    else res.push_back(*s.begin());
                }
            }
        }
        return res;
    }
};
