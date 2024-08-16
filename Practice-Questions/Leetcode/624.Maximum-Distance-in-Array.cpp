class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        const int m = arrays.size();
        int res = 0;
        int mn = arrays.front().front();
        int mx = arrays.front().back();
        for (int i = 1; i < m; ++ i)
        {
            res = max({res, arrays[i].back() - mn, mx - arrays[i].front()});
            mx = max(mx, arrays[i].back());
            mn = min(mn, arrays[i].front());
        }
        return res;
    }
};