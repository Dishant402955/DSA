static constexpr int MOD = 1e9 + 7, MAX = 500;
static int dp[MAX];
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        memset(dp , 0 , n * sizeof(int));
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            int right = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) swap(right , dp[j]);
                else {
                    int sum = dp[j] + right;
                    if (sum >= MOD) sum -= MOD;
                    dp[j] = right = sum;
                }
            }
        }
        return dp[n - 1];
    }
};
