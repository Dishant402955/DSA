class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int s1 = 0, s2 = 0, s3 = 0, s4;
        for (int i = 0; i < n; ++i) {
            s4 = costs[i] + min({
                s3 + 1,
                s2 + 4,
                s1 + 9
            });
            s1 = s2;
            s2 = s3;
            s3 = s4;
        }
        return s4;
    }
};
