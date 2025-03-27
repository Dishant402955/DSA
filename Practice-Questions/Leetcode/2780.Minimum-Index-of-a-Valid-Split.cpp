class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp1, mp2;

        // Count the occurrences of each element
        for (int num : nums) {
            mp1[num]++;
        }

        // Iterate to find the minimum index for a valid split
        for (int i = 0; i < nums.size(); i++) {
            mp1[nums[i]]--;
            mp2[nums[i]]++;

            if (mp1[nums[i]] * 2 > nums.size() - i - 1 && 
                mp2[nums[i]] * 2 > i + 1) {
                return i;
            }
        }
        return -1;
    }
};