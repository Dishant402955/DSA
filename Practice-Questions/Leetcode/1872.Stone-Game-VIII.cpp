#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        // Step 1: Compute prefix sums in-place to save space
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        
        // Step 2: Initialize DP from the rightmost valid move
        // A player taking all stones gets stones[n - 1]
        int max_diff = stones[n - 1];
        
        // Step 3: Iterate backwards from n - 2 down to 1
        // Each step updates the maximum score difference available
        for (int i = n - 2; i >= 1; --i) {
            max_diff = std::max(max_diff, stones[i] - max_diff);
        }
        
        return max_diff;
    }
};
