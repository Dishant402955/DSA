class Solution {

public:

    string reverseParentheses(string s) {

        stack<int> Indexes;

        string ans;

        for (char ch : s) {

            if (ch == '(') {
                Indexes.push(ans.length());
            }
            else if (ch == ')') {
                int start = Indexes.top();
                Indexes.pop();
               
                reverse(ans.begin() + start, ans.end());
            }
            else {
            
                ans += ch;
            }

        }
        return ans;
    }
};