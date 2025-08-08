class Solution {
public:
    double f(int a, int b, vector<vector<double>> &dp){
        if(b <= 0 and a <= 0)
            return 0.5;
        if(a <=0)
            return 1.0;
        if(b<=0)
            return 0.0;
        if(dp[a][b] >= 0)
            return dp[a][b];
        double case1 = f(a-4, b, dp);
        double case2 = f(a-3, b-1, dp);
        double case3 = f(a-2, b-2, dp);
        double case4 = f(a-1, b-3, dp);
        return dp[a][b] = 0.25 * (case1 + case2 + case3 + case4);
    }

    double soupServings(int n) {
        if(n >= 5785)
            return 1;
        n = (n + 24)/25;
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1.0));
        return f(n, n, dp);
    }
};
