class Solution {
public:
    int prefixCount(vector<string>& words, string& pref) {
        return accumulate(words.begin(), words.end(), 0,
        [pref](int sum, auto& w){
            return sum+=w.starts_with(pref);
        });
    }
};