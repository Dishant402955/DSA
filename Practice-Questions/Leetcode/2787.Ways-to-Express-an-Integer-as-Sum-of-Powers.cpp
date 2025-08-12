class Solution {
public:
    const int MOD = 1e9 + 7;
    int solver(int n, int x, int start,vector<vector<int>>& dp) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (pow(start, x) > n) return 0;

        if(dp[n][start]!=-1) return dp[n][start];

        int res = pow(start, x);
        int take = solver(n - res, x, start + 1,dp)%MOD;
        int skip = solver(n, x, start + 1,dp)%MOD;

        return dp[n][start] = (take + skip)%MOD;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solver(n, x, 1,dp);
    }
};
