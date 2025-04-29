class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        auto it = std::max_element(nums.begin(), nums.end());
        long long m = *it;
        long long t = 0;
        long long left = 0, right = 0;
        long long count = 0;
        int len = nums.size();
        for (right = 0; right < len; right++) {
            if (nums[right] == m)
                t++;
            while (t >= k) {
                if (nums[left] == m) {
                    t--;
                }
                left++;
            }
            count+=left;
        }
        return count;
    }
};