class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> result(n);
        int level = 0;

        for (int i = 0; i < n; ++i) {
            if (seq[i] == '(') {
                ++level;
                result[i] = level & 1;
            } else {
                result[i] = level & 1;
                --level;
            }
        }

        return result;
    }
};
