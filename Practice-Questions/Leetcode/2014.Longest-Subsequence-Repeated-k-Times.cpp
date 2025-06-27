class Solution {
public:
   bool check(string &s, string &p, int k) {
    for (int i = 0, j = 0; i < s.size() && k > 0; ++i) {
        j += p[j] == s[i];
        if (j == p.size()) {
            --k;
            j = 0;
        }
    }
    return k == 0;
}
void generate(string &s, string &chars, string &cur, string &best, int mask, int k) {
    for (int i = 0; i < chars.size(); ++i) {
        if ((mask & (1 << i)) == 0) {
            string new_cur = cur + chars[i];
            if (check(s, new_cur, k)) {
                if (new_cur.size() > best.size())
                    best = new_cur;
                generate(s, chars, new_cur, best, mask + (1 << i), k);
            }
        }
    }
}
string longestSubsequenceRepeatedK(string &s, int k) {
    int cnt[26] = {};
    string chars, best;
    for (auto ch : s)
        ++cnt[ch - 'a'];
    for (int i = 25; i >= 0; --i)
        chars += string(cnt[i] / k, 'a' + i);
    generate(s, chars, string() = {}, best, 0, k);
    return best;
}
};
