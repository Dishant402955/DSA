class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_num = nums;
        sort(sorted_num.begin(), sorted_num.end());
        vector<int> expected;
        for (int i = 1; i < n; i++) {
            expected.push_back(i);
        }

        expected.push_back(n - 1);
        return expected == sorted_num;
    }
};
