class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mappa;
        for(string word: words){
            mappa[word]++;
        }

        int res = 0;
        bool oddSymmetrics = false;
        for(auto [word, freq]: mappa){
            string reversedWord = string(word.rbegin(), word.rend());
            if(word == reversedWord){
                res += freq - freq%2;
                if(freq % 2)
                    oddSymmetrics = true;
            }
            else
                res += min(freq, mappa[reversedWord]);
        }
        if(oddSymmetrics)
            res += 1;
        return res*2;
    }
};