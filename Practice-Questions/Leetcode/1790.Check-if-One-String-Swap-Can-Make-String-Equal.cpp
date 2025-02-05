class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        int freq1[26] = {0}, freq2[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                return false;
        }
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i])
                count++;
        }
        return count <= 2;
    }
};