class Solution {
public:
    int f(int i, vector<int>& stones, vector<int> &dp){
        if(i >= stones.size())
            return 0;
        if(dp[i] != INT_MIN)
            return dp[i];
        int res = stones[i] - f(i + 1, stones, dp);
        if(i + 1 < stones.size())
            res = max(res, stones[i] + stones[i+1] - f(i+2, stones, dp));
        if(i + 2 < stones.size())
            res = max(res, stones[i] + stones[i+1] + stones[i+2] - f(i+3, stones, dp));
        return dp[i] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(), INT_MIN);
        int res = f(0, stoneValue, dp);
        if(res > 0)
            return "Alice";
        else if(res < 0)
            return "Bob";
        return "Tie";
    }
};
