
class Solution {
private:
    void calculation(string &tiles, unordered_map<char, int> &mp, string current, set<string> &ans) {
        if (!current.empty()) {
            ans.insert(current);
        }

        for (auto &entry : mp) {
            if (entry.second > 0) {
                entry.second--; 
                calculation(tiles, mp, current + entry.first, ans);
                entry.second++; 
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> mp;

        for (char ch : tiles) {
            mp[ch]++;
        }
        set<string> ans;
        calculation(tiles, mp, "", ans);
        return ans.size(); 
    }
};