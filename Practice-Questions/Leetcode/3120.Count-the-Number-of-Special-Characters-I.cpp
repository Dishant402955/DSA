class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> low(26, false);
        vector<bool> up(26, false);

        for (char c : word) {
            // Lowercase character
            if (c >= 'a' && c <= 'z') {
                low[c - 'a'] = true;
            }
            // Uppercase character
            else {
                up[c - 'A'] = true;
            }
        }
        int ans = 0;
        // Count characters present in both
        for (int i = 0; i < 26; i++) {
            if (low[i] && up[i]) {
                ans++;
            }
        }
        return ans;
    }
};
