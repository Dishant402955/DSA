class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int res = 2;
        
        // Try all possible starting mod values
        for (int j = 0; j < k; ++j) {
            vector<int> dp(k, 0);  // dp[mod] = length of sequence ending with mod

            for (int num : nums) {
                int mod = num % k;
                int pos = (j - mod + k) % k;  // Adjusted for negative values
                dp[mod] = dp[pos] + 1;
            }

            for (int len : dp) {
                res = max(res, len);
            }
        }

        return res;
    }
};
