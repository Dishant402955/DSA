class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, prev_set, curr_set;

        for (int cv : arr) {
            curr_set.clear();
            curr_set.insert(cv);
            for (int val : prev_set) {
                curr_set.insert(val | cv);
            }
            prev_set = curr_set;
            res.insert(curr_set.begin(), curr_set.end());
        }

        return res.size();
    }
};
