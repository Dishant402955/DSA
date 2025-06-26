class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cur = 0;
        int ans = 0;
        long long val = 0;
        bool flag = false;
        for (int i = s.size() - 1; i >= 0; i --) {
            if (s[i] == '0') ans ++, cur ++; else {
                if (!flag && cur < 32 && (val | (1ll << cur)) <= k) {
                    ans ++;
                    val |= 1 << cur;
                    cur ++;
                }
                if (cur < 32 && (val | 1ll << cur) > k) flag = true;
            }
        }
        cout << val;
        return ans;
    }
};
