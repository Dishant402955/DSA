class Solution {
    int MOD = 1E9+7;
    // Part 1: Data for combinatorics C(i, j)
    vector<vector<long long>> combin;
    void constructPascal(int M){
        // combin[i][j] == C i pick j in Math
        combin.resize(M+1, vector<long long>(M+1, 0));
        for(int i=0; i<=M; ++i){ 
            combin[i][0] = combin[i][i] = 1;
        }
        for(int i=2; i<=M; ++i){
            for(int j=1; j<M; ++j){
                // Ci,j = Ci-1,j + Ci-1,j-1
                combin[i][j] = (combin[i-1][j] + combin[i-1][j-1]) % MOD;
            }
        }
    }
    // Part 2:Data for dynamic programming
    int dp[50][31][31][16];
    int runDP(int cur, int m, int k, int carry_mask, vector<int>& nums){
        if(m == 0){ // can not add anymore nums
            bitset<5> bit = carry_mask;
            if(bit.count() == k) return 1;
            else return 0;
        }
        if(k == 0 || cur == nums.size()) return 0; // because m != 0 but already no nums to pick
        if(dp[cur][m][k][carry_mask] != -1) return dp[cur][m][k][carry_mask];
        // Start top-down DP, try to add nums[cur] 0-m times
        long long res = 0;
        long long prod = 1;
        for(int add = 0; add <= m; ++add){
            int curMask = carry_mask + add; // at most 30
            int nextK = k - (curMask & 1);
            int nextM = m - add;
            if(add) prod = (prod * nums[cur]) % MOD;
            long long temp = (combin[m][add] * prod) % MOD;
            res = (res + temp * runDP(cur+1, nextM, nextK, curMask >> 1, nums)) % MOD;
        }
        return dp[cur][m][k][carry_mask] = res;
    }
public:
    int magicalSum(int M, int K, vector<int>& nums) {
        int n = nums.size();
        // 1. construct the combinatorics matrix with pascal theorm
        constructPascal(M);
        // 2. Run Top-down dp table
        memset(dp, -1, sizeof(dp));
        return runDP(0, M, K, 0, nums);;
    }
};
