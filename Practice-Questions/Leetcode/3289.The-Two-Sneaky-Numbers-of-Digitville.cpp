class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        bitset<101> b;
        int k = 0, n = nums.size();
        for (int i = 0; i != n && k != 2; ++i) {
            int v = nums[i];
            nums[k] = v;
            k += b[v];
            b[v] = 1;
        }

        nums.resize(2);
        return std::move(nums);
    }
};
