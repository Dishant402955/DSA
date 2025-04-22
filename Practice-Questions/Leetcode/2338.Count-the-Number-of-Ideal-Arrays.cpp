class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX = 10010;
    vector<vector<int>> factors;

    // Precompute factorials and inverse factorials
    vector<long long> fac, inv;

    // Fast exponentiation
    long long power(long long x, long long y) {
        long long res = 1;
        x = x % MOD;
        while (y > 0) {
            if (y & 1)
                res = (res * x) % MOD;
            y = y >> 1;
            x = (x * x) % MOD;
        }
        return res;
    }

    // Precompute factorials and inverse factorials up to MAX
    void initComb(int n) {
        fac.resize(n + 1);
        inv.resize(n + 1);
        fac[0] = inv[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fac[i] = fac[i - 1] * i % MOD;
        }
        inv[n] = power(fac[n], MOD - 2);
        for (int i = n - 1; i >= 1; --i) {
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }
    }

    long long comb(int n, int k) {
        if (k > n || k < 0) return 0;
        return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
    }

    int idealArrays(int n, int maxValue) {
        initComb(n + 100); // initialize combinatorics

        vector<vector<long long>> dp(15, vector<long long>(maxValue + 1, 0));

        for (int i = 1; i <= maxValue; ++i) {
            dp[1][i] = 1;
        }

        for (int len = 2; len < 15; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int j = i * 2; j <= maxValue; j += i) {
                    dp[len][j] = (dp[len][j] + dp[len - 1][i]) % MOD;
                }
            }
        }

        long long res = 0;

        for (int len = 1; len < 15; ++len) {
            long long sum = 0;
            for (int i = 1; i <= maxValue; ++i) {
                sum = (sum + dp[len][i]) % MOD;
            }
            res = (res + sum * comb(n - 1, len - 1) % MOD) % MOD;
        }

        return (int)res;
    }
};