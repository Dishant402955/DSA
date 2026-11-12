class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int best = 1;
        int start = 0;
        int n = nums.size();
        // Each maximal monotone run is a block between "breaks".
        // A run begins at 'start'; its direction is set by the first pair.
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                start = i;
                continue;
            }
            // Direction changes when the sign of the step differs from the previous step.
            if (i >= 2 && nums[i - 1] != nums[i - 2]
                && ((nums[i] > nums[i - 1]) != (nums[i - 1] > nums[i - 2]))) {
                start = i - 1;
            }
            best = max(best, i - start + 1);
        }
        return best;
    }
};
