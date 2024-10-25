class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        unordered_set<string> set;
        for (const auto &dir : folder) {
            string parentDir;
            bool isSubfolder = false;
            for (size_t i = 1; i < dir.size(); i++) {
                if (dir[i] == '/') {
                    parentDir = dir.substr(0, i);
                    if (set.count(parentDir)) {
                        isSubfolder = true;
                        break;
                    }
                }
            }
            if (!isSubfolder) {
                set.insert(dir);
            }
        }
        return vector<string>(set.begin(), set.end());
    }
};