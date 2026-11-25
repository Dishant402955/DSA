class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        int left = 1;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (hasUniqueSubarray(nums, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool hasUniqueSubarray(const vector<int>& nums, int length) {
        int n = (int)nums.size();

        if (length > n) {
            return false;
        }

        const long long mod1 = 1000000007LL;
        const long long mod2 = 1000000009LL;
        const long long base = 9113823LL;

        long long power1 = 1;
        long long power2 = 1;

        for (int i = 0; i < length - 1; ++i) {
            power1 = power1 * base % mod1;
            power2 = power2 * base % mod2;
        }

        unordered_map<long long, int> frequency;
        frequency.reserve(n * 2);

        long long hash1 = 0;
        long long hash2 = 0;

        for (int i = 0; i < length; ++i) {
            hash1 = (hash1 * base + nums[i]) % mod1;
            hash2 = (hash2 * base + nums[i]) % mod2;
        }

        frequency[hash1 * mod2 + hash2]++;

        for (int i = length; i < n; ++i) {
            hash1 = (hash1 - nums[i - length] * power1 % mod1 + mod1) % mod1;
            hash1 = (hash1 * base + nums[i]) % mod1;

            hash2 = (hash2 - nums[i - length] * power2 % mod2 + mod2) % mod2;
            hash2 = (hash2 * base + nums[i]) % mod2;

            frequency[hash1 * mod2 + hash2]++;
        }

        for (const auto& entry : frequency) {
            if (entry.second == 1) {
                return true;
            }
        }

        return false;
    }
};
