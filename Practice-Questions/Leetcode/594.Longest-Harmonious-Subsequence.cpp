class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        int ans = 0;
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) 
        {
            if (nums[1] - nums[0] == 1) return 2;
            else return 0;
        }
        while (i <= j && j < nums.size())
        {
            if (nums[j] - nums[i] == 1)
            {
                ans = max(ans, j-i+1);
                j++;
            }
            else if (nums[j] - nums[i] > 1)
            {
                i++;
            }
            else
            {
                j++;
            }

        }
        return ans;
    }
};
