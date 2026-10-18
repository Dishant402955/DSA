class Solution {
public:
    static const int MOD = 1'000'000'007;
    vector<vector<int>> pt;

    long long solve(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 1;

        vector<int> left, right;
        int root = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long x = solve(left);
        long long y = solve(right);
        long long z = pt[n - 1][left.size()];

        return x * y % MOD * z % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Precompute combinations.
        pt.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            pt[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                pt[i][j] =
                    (pt[i - 1][j - 1] + pt[i - 1][j]) % MOD;
            }
        }

        // Subtract the original ordering.
        return (solve(nums) - 1 + MOD) % MOD;
    }
};
