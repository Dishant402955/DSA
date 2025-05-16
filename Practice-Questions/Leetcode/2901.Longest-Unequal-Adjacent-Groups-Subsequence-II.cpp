class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> next(n, -1);
        vector<int> len(n, 1);
        int ans = 1, longestStartInd = 0;
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (words[i].length() == words[j].length()) {
                    int diff = 0;
                    for (int k = 0; k < words[i].length(); k++) {
                        if (words[i][k] != words[j][k]) {
                            diff++;
                            if (diff > 1) break;
                        }
                    }
                    // Can connect if valid
                    if (diff == 1 && groups[i] != groups[j]) {
                        // Connect to the longest successor
                        if (next[i] == -1 || len[j] > len[next[i]]) {
                            next[i] = j;
                            len[i] = len[j] + 1;
                            if (len[i] > ans) {
                                ans = len[i];
                                longestStartInd = i;
                            }
                        }
                    }
                }
            }
        }
        
        vector<string> ansList;
        while (longestStartInd != -1) {
            ansList.push_back(words[longestStartInd]);
            longestStartInd = next[longestStartInd];
        }
        
        return ansList;
    }
};