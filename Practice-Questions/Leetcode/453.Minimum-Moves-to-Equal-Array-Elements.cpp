class Solution {
public:
    int minMoves(vector<int>& a) {
        int lo = INT_MAX / 2, x = 0;
        for (int i{}; int v : a) {
            x += i++ * max(lo - v, 0);
            x += v - (lo = min(lo, v));
        }
        return x;
    }
};
