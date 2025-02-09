class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> count;
        long long n = nums.size(), equal = 0;
        for(int i = 0; i < n; ++i) count[nums[i]-i]++;
        
		// counting pairs with equal difference between number and it's index
		// ex. if count[4] = 6, then there will be total (6 * 5) / 2  = 15 unique pairs
        for(auto& it: count) equal += ((it.second * (it.second-1)) / 2);
        
		// total possible pairs in array
        long long total = (n * (n-1)) / 2;
		
		// not equal = total - equal
        return total - equal;
    }
};