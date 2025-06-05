class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int UtimateParent(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = UtimateParent(parent[u]);
    }

    bool SameComponent(int u, int v) {
        return UtimateParent(u) == UtimateParent(v);
    }

    void Union(int u, int v) {
        int ulp_u = UtimateParent(u), ulp_v = UtimateParent(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size(), m = baseStr.size();
        DisjointSet ds(26);
        for (int i = 0; i < n; i++) {
            ds.Union(s1[i] - 'a', s2[i] - 'a');
        }
        vector<char> chmap(26, 'z');
        for (int i = 0; i < 26; i++) {
            int ulp_c = ds.UtimateParent(i);
            if (chmap[ulp_c] > i + 'a') {
                chmap[ulp_c] = i + 'a';
            }
        }
        string res = "";
        for (int i = 0; i < m; i++) {
            res += chmap[ds.UtimateParent(baseStr[i] - 'a')];
        }
        return res;
    }
};