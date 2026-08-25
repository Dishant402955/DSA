class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> numbers(nums.begin(), nums.end());

        int currentMultiple = k;

        while (numbers.count(currentMultiple)) {
            currentMultiple += k;
        }

        return currentMultiple;
    }
};
