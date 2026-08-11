class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        // Intuition: sum sequential prefix, then linear scan for first missing value
        int sum = nums[0];
        int i = 1;
        while (i < (int)nums.size() && nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }

        int candidate = sum;
        while (true) {
            bool found = false;
            for (int num : nums) {
                if (num == candidate) {
                    found = true;
                    break;
                }
            }
            if (!found) return candidate;
            candidate++;
        }
    }
};
