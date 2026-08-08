class Solution {
public:
    vector<int> validSequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int j = m - 1;
        vector<int> v(n, 0);
        v.push_back(m);
        
        for (int i = n - 1; i >= 0; i--) {
            v[i] = v[i + 1];
            if (j >= 0 and s1[i] == s2[j]) {
                v[i] = j;
                j--;
            }
        }
        
        j = 0; 
        int swapind = -1;
        
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[j]) {
                j++;
            } else if (v[i + 1] <= j + 1) {
                swapind = j;
                break;
            }
        }
        
        j = 0;
        vector<int> ans;
        
        for (int i = 0; i < n and j < m; i++) {
            if (j == swapind) {
                ans.push_back(i);
                j++;
            } else if (s1[i] == s2[j]) {
                ans.push_back(i);
                j++;
            }
        }
        
        return (ans.size() < m ? vector<int>(0) : ans);
    }
};
