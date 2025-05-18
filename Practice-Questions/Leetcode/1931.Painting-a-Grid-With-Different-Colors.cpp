class Solution {
public:
    long long MOD;
    vector<vector<long long>> dp;

    long long fun(long long column, long long row, long long lastcolColor, long long currcolColor, int m, int n) {
        if (row == m) {
            row = 0;
            lastcolColor = currcolColor;
            currcolColor = 0;
            return fun(column + 1, row, lastcolColor, currcolColor, m, n) % MOD;
        }
        if (column == n)
            return 1;

        if (row == 0 && dp[column][lastcolColor] != -1)
            return dp[column][lastcolColor];

        // Extract left-adjacent color
        long long isred = lastcolColor & (1LL << (2 * row));  
        long long isblue = lastcolColor & (1LL << (2 * row + 1));
        long long isgreen = isred && isblue;  
        long long leftCol = isgreen ? 3 : (isblue ? 2 : (isred ? 1 : 0));

        // Extract top-adjacent color
        long long upCol = 0;
        if (row != 0) {
            long long isred = currcolColor & (1LL << (2 * (row - 1)));  
            long long isblue = currcolColor & (1LL << (2 * (row - 1) + 1));
            long long isgreen = isred && isblue;
            upCol = isgreen ? 3 : (isblue ? 2 : (isred ? 1 : 0));
        }

        long long res = 0;
        for (long long j = 1; j <= 3; j++) {
            if (j != upCol && j != leftCol) {
                res = (res % MOD + fun(column, row + 1, lastcolColor, currcolColor | (j * (1 << (2 * row))), m, n) % MOD) % MOD;
            }
        }

        if (row == 0) dp[column][lastcolColor] = res;
        return res;
    }

    int colorTheGrid(int rows, int cols) {
        MOD = 1e9 + 7;
        dp.resize(1001, vector<long long>(1025, -1));
        return fun(0, 0, 0, 0, rows, cols);
    }
};