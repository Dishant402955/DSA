class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> count(26, 0);
        long long sum = 0;

        for (char c : s) {
            long long total = (1 + sum) % MOD;
            int idx = c - 'a';

            sum = (sum + total - count[idx] + MOD) % MOD;
            count[idx] = total;
        }

        return (int)sum;
    }
};
