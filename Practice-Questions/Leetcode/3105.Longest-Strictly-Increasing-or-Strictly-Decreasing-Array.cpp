class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1; // Track current increasing and decreasing lengths
        int il = 1, dl = 1;   // Track longest increasing and decreasing lengths

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                il++;          // Increment increasing length
                inc = max(inc, il); // Update longest increasing length
                dl = 1;        // Reset decreasing length
            } else if (nums[i] > nums[i + 1]) {
                dl++;          // Increment decreasing length
                dec = max(dec, dl); // Update longest decreasing length
                il = 1;        // Reset increasing length
            } else {
                il = 1;        // Reset both lengths if elements are equal
                dl = 1;
            }
        }
        return max(inc, dec);  // Return the maximum length found
    }
};

