class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int length = piles.size();
        vector<vector<int>> dp(length + 1, vector<int>(length + 1,0));
        vector<int> sufsum (length + 1, 0);
        for (int i = length - 1; i >= 0; i--) {
            sufsum[i] = sufsum[i + 1] + piles[i];
        }
        return helper(dp, sufsum, 0, 1);
    }
    
    int helper(vector<vector<int>>& dp, vector<int>& sufsum, int i, int M) {
        if (i == sufsum.size()) return 0;
        if (2*M >= sufsum.size() - i) return sufsum[i];
        if (dp[i][M] != 0) return dp[i][M];
        int res = INT_MAX;
        for (int X = 1; X <= 2*M; X++) {
            res = min(res, helper(dp, sufsum, i+X, max(X,M)));
        }
        dp[i][M] = sufsum[i] - res;
        return dp[i][M];
    }
};