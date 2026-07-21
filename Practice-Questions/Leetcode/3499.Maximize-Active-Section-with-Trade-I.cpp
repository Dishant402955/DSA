class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> freq = {1};
        for (auto it : s) {
            if (it == '0') {
                if (freq.size() % 2 == 0) {
                    freq.back()++;
                } else {
                    freq.push_back(1);
                }
            } else {
                if (freq.size() % 2 == 1) {
                    freq.back()++;
                } else {
                    freq.push_back(1);
                }
            }
        }
        if (freq.size() % 2 == 1) {
            freq.back()++;
        } else {
            freq.push_back(1);
        }
        int sol = -2;
        if (freq.size() <= 3) {
            for (int i = 0; i < freq.size(); i += 2) {
                sol += freq[i];
            }
            return sol;
        }
        for (int i = 0; i < freq.size(); i += 2) {
            sol += freq[i];
        }
        int toAdd = freq[1];
        for (int i = 3; i < freq.size(); i += 2) {
            toAdd = max(toAdd, (freq[i] + freq[i - 2]));
        }
        sol += toAdd;
        return sol;
    }
};
