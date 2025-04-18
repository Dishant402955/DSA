class Solution {
public:
    string solve(int i, int n, string str) {
        if (i == n)
            return str;
        string op;
        int j = 0,k;
        for ( k = 1; k < str.size(); k++) {
            if (str[k] != str[k - 1]) {
                char c = str[k - 1];
                int times = k - j;
                j = k;
                op += to_string(times);
                op += c;
            }
        }
        char c = str[k - 1];
        int times = k - j;
        j = k;
        op += to_string(times);
        op += c;
        return solve(i + 1, n, op);
    }
    string countAndSay(int n) {
        int i = 1;
        return solve(i, n, "1");
    }
};