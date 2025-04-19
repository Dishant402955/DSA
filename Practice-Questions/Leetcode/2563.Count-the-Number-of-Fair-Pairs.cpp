class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // Sort the array to enable binary search
        sort(nums.begin(), nums.end());
        long long count = 0;

        // Check for each nums[i] how many nums[j] (j > i) give a fair pair
        for (int i = 0; i < nums.size(); i++) {
            // Use binary search to find bounds
            auto left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);

            // Count number of valid j values
            count += right - left;
        }

        return count;
    }
};