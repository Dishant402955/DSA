class Solution {
public:
    vector<string> createGrid(int m, int n) {
        if (m == 1) return vector<string>{string(n, '.')};
        if (n == 1) return vector<string>(m, ".");

        vector<string> dp(m, string(n, '#'));

        dp[0][0] = '.';
        dp[0][1] = '.';

        int lr = 0;
        int lc = 1;

        for (int i = 1; i < m; i++) {
            if (lr + 1 < m)
                dp[lr + 1][lc] = '.';

            if (lc + 1 < n) {
                dp[lr + 1][lc + 1] = '.';
                lc++;
            }

            lr++;
        }

        while (lc < n)
            dp[lr][lc++] = '.';

        return dp;
    }
};
