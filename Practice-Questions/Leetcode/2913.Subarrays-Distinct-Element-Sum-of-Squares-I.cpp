class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> hash;

            for (int j = i; j < nums.size(); j++) {
                hash.insert(nums[j]);
                sum += hash.size() * hash.size();
            }
        }

        return sum;
    }
};
