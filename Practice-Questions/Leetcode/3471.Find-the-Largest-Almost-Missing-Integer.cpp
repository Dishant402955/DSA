class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51, 0);
        int maxEle = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            maxEle = max(maxEle, nums[i]);
        }

        if (k == 1) {
            for (int i = 50; i >= 0; i--) {
                if (freq[i] == 1)
                    return i;
            }
        } else if (k == n) {
            return maxEle;
        } else {
            if (freq[nums[0]] == 1 && freq[nums[n - 1]] == 1)
                return max(nums[0], nums[n - 1]);
            else if (freq[nums[0]] == 1 && freq[nums[n - 1]] != 1)
                return nums[0];
            else if (freq[nums[0]] != 1 && freq[nums[n - 1]] == 1)
                return nums[n - 1];
        }
        return -1;
    }
};
