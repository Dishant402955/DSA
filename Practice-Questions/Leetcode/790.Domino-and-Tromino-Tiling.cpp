class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        vector<long long> arr(max(3, n));
        arr[0] = 1; // n = 1
        arr[1] = 2; // n = 2
        arr[2] = 5; // n = 3
        for (int i = 3; i < n; ++i) {
            arr[i] = (2 * arr[i - 1] % MOD + arr[i - 3]) % MOD;
        }
        return arr[n - 1];
    }
};