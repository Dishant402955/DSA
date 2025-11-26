class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;
        // dp[i][j][r] = number of paths to (i,j) with sum % k = r
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        // Base case: at (0,0), sum is just grid[0][0]
        dp[0][0][grid[0][0] % k] = 1;
        // Fill the DP table row by row
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Skip the base case cell
                if (i == 0 && j == 0) continue;
                // Try all possible remainders from previous cells
                for (int r = 0; r < k; r++) {
                    // After adding current cell, new remainder is:
                    int newR = (r + grid[i][j]) % k;
                    // Coming from above (i-1, j)
                    if (i > 0) {
                        dp[i][j][newR] = (dp[i][j][newR] + dp[i-1][j][r]) % MOD;
                    }
                    // Coming from left (i, j-1)
                    if (j > 0) {
                        dp[i][j][newR] = (dp[i][j][newR] + dp[i][j-1][r]) % MOD;
                    }
                }
            }
        }
        // Return paths with remainder 0 (divisible by k)
        return dp[m-1][n-1][0];
    }
};
