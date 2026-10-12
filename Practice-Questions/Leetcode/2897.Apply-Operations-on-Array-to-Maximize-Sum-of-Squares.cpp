#include <vector>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1000000007LL;
        int bitCount[30] = {};

        for (int num : nums) {
            for (int bit = 0; bit < 30; ++bit) {
                if ((num >> bit) & 1) {
                    ++bitCount[bit];
                }
            }
        }

        long long result = 0;

        for (int i = 0; i < k; ++i) {
            long long currentNum = 0;

            for (int bit = 0; bit < 30; ++bit) {
                if (bitCount[bit] > 0) {
                    currentNum |= (1LL << bit);
                    --bitCount[bit];
                }
            }

            result = (result + currentNum * currentNum) % MOD;
        }

        return static_cast<int>(result);
    }
};
