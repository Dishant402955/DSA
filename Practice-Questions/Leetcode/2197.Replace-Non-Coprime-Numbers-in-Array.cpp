class Solution {
public:
    int findGCD(int a, int b) {
        if (b == 0)
            return a;
        return findGCD(b, a % b);
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;

        for (int num : nums) {
            int cur = num;

            while (!st.empty()) {
                int g = findGCD(st.top(), cur);
                if (g == 1)
                    break;
                cur = (st.top() / g) * cur; // LCM
                st.pop();
            }

            st.push(cur);
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
