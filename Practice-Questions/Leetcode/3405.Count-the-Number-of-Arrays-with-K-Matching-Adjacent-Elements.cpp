class Solution {
    int MOD = 1e9 + 7;
public:
    int countGoodArrays(int n, int m, int k) {
        vector<long long> fact(n + 1, 1);
        for(int i = 2; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        long long res = nCr(n - 1, k, fact) * m % MOD * powerMOD(m - 1, n - k - 1) % MOD;
        return res;
    }
private:
    long long nCr(int n, int r, vector<long long>& fact) {
        return (fact[n] * modInverse(fact[r]) % MOD * modInverse(fact[n - r]) % MOD) % MOD;
    }

    long long modInverse(long long x) {
        return powerMOD(x, MOD - 2);
    }

    long long powerMOD(int base, int pw) {
        if(pw == 0)
            return 1;
        
        long long tmp = powerMOD(base, pw >> 1) % MOD;

        if(pw & 1) return (base * ((tmp * tmp) % MOD)) % MOD;
        return (tmp * tmp) % MOD;
    }
};
