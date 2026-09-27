class Solution {
public:
    string reverseStr(string s)
    {
        int l = 0, r = s.length() - 1;

        while (l < r)
        {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;

            l++;
            r--;
        }

        return s;
    }

    pair<string, int> solve(int i, string& s)
    {
        if (i >= s.length())
            return {"", s.length()};

        string ans = "";

        if (s[i] != '(')
            ans += s[i];

        int to_ret = s.length() - 1;
        bool flag = false;

        for (int j = i + 1; j < s.length(); j++)
        {
            if (isalpha(s[j]))
            {
                ans += s[j];
            }
            else if (s[j] == '(')
            {
                auto it = solve(j, s);

                ans += it.first;
                j = it.second;
            }
            else if (s[j] == ')')
            {
                to_ret = j;
                flag = true;
                break;
            }
        }

        if (flag)
            ans = reverseStr(ans);

        return {ans, to_ret};
    }

    string reverseParentheses(string s)
    {
        string ans = "";

        for (int j = 0; j < s.length(); j++)
        {
            if (isalpha(s[j]))
            {
                ans += s[j];
            }
            else if (s[j] == '(')
            {
                auto it = solve(j, s);

                ans += it.first;
                j = it.second;
            }
            else if (s[j] == ')')
            {
                ans = reverseStr(ans);
            }
        }

        return ans;
    }
};
