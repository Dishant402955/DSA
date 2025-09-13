class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        string vowels = "aeiou";
        int maxVowel = 0, maxConsonant = 0;

        for (char c : s) {
            int idx = c - 'a';
            freq[idx]++;

            if (vowels.find(c) != string::npos) {
                maxVowel = max(maxVowel, freq[idx]);
            } else {
                maxConsonant = max(maxConsonant, freq[idx]);
            }
        }

        return maxVowel + maxConsonant;
    }
};
