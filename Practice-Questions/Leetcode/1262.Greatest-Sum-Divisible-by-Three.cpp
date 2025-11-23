class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, INT_MIN);
        dp[0] = 0;
        
        for (int x : nums) {
            vector<int> temp = dp;
            for (int r = 0; r < 3; r++) {
                int newR = (r + x % 3) % 3;
                temp[newR] = max(temp[newR], dp[r] + x);
            }
            dp = temp;
        }
        
        return dp[0];
    }
};
