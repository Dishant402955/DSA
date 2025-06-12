class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int a = nums[0] - nums[nums.size() - 1];
        int maxVal = abs(a);
        for (int i = 0; i < nums.size() - 1; i++) {
            int b = nums[i] - nums[i + 1];
            b = abs(b);
            if (maxVal < b)
                maxVal = b;
        }
        return maxVal;
    }
};
