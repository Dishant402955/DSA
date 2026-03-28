class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) parent[b] = a;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        // Step 1: Validate diagonal
        for(int i = 0; i < n; i++) {
            if(lcp[i][i] != n - i) return "";
        }

        // DSU initialization
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        // Step 2: Union indices where lcp > 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(lcp[i][j] > 0) {
                    unite(i, j);
                }
            }
        }

        // Step 3: Assign characters
        vector<char> res(n);
        unordered_map<int, char> mp;
        char curr = 'a';

        for(int i = 0; i < n; i++) {
            int p = find(i);
            if(mp.count(p) == 0) {
                if(curr > 'z') return "";
                mp[p] = curr++;
            }
            res[i] = mp[p];
        }

        string word(res.begin(), res.end());

        // Step 4: Recompute LCP
        vector<vector<int>> check(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(word[i] == word[j]) {
                    if(i + 1 < n && j + 1 < n)
                        check[i][j] = 1 + check[i+1][j+1];
                    else
                        check[i][j] = 1;
                }
            }
        }

        if(check != lcp) return "";

        return word;
    }
};
