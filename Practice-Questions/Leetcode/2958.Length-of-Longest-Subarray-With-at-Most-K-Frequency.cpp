class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int res = 0;

        unordered_map<int, int> count;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            count[nums[i]]++;

            while (count[nums[i]] > k) {
                count[nums[left]]--;
                left++;
            }

            res = max(res, i - left + 1);
        }

        return res;
    }
};
