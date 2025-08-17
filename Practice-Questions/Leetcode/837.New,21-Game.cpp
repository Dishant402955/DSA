class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // Edge cases
        if (k == 0) return 1.0;
        if (n >= k - 1 + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double window = 1.0; // sum of probabilities in the sliding window
        double ans = 0.0;

        for (int x = 1; x <= n; ++x) {
            dp[x] = window / maxPts;

            if (x < k) {
                window += dp[x];  // still a drawing state
            } else {
                ans += dp[x];     // terminal state (>=k)
            }

            if (x - maxPts >= 0) {
                if (x - maxPts < k) {
                    window -= dp[x - maxPts];
                }
            }
        }
        return ans;
    }
};
