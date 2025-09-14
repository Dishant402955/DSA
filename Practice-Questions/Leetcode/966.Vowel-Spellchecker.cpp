class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> wordSet(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lowerMap;
        unordered_map<string, string> vowelMap;

        for (const string& word : wordlist) {
            string lowerWord = toLower(word);
            string devowelWord = devowel(lowerWord);

            // Insert only the first occurrence
            if (lowerMap.find(lowerWord) == lowerMap.end())
                lowerMap[lowerWord] = word;

            if (vowelMap.find(devowelWord) == vowelMap.end())
                vowelMap[devowelWord] = word;
        }

        vector<string> result;
        for (const string& query : queries) {
            if (wordSet.count(query)) {
                // Exact match (case-sensitive)
                result.push_back(query);
            } else {
                string lowerQuery = toLower(query);
                string devowelQuery = devowel(lowerQuery);

                if (lowerMap.count(lowerQuery))
                    result.push_back(lowerMap[lowerQuery]);
                else if (vowelMap.count(devowelQuery))
                    result.push_back(vowelMap[devowelQuery]);
                else
                    result.push_back("");
            }
        }

        return result;
    }

private:
    string toLower(const string& word) {
        string res = word;
        transform(res.begin(), res.end(), res.begin(), ::tolower);
        return res;
    }

    string devowel(const string& word) {
        string res = word;
        for (char& ch : res) {
            if (isVowel(ch)) {
                ch = '*';
            }
        }
        return res;
    }

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};
