class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;
        int count = 0;

        while (ss >> word) {
            bool canBeTyped = true;
            for (char ch : word) {
                if (brokenLetters.find(ch) != string::npos) {
                    canBeTyped = false;
                    break;
                }
            }

            if (canBeTyped) {
                count++;
            }
        }
        return count;
    }
};
