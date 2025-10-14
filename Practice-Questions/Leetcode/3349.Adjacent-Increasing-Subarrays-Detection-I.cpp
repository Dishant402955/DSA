class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        auto isIncreasing = [&](int start) {
            for (int i = start; i < start + k - 1; ++i) {
                if (nums[i] >= nums[i + 1]) return false;
            }
            return true;
        };
        
        for (int i = 0; i + 2 * k <= n; ++i) {
            if (isIncreasing(i) && isIncreasing(i + k))
                return true;
        }
        
        return false;
    }
};
