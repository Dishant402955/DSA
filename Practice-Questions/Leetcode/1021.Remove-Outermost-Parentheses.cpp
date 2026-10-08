class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string res;

        for(char ch : s) {
            if(ch == '(') {
                if(open > 0) {
                    res += ch;
                }
                open++;
            }
            else {
                open--;
                if(open > 0) {
                    res += ch;
                }
            }
        }

        return res;
    }
};
