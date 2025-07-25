#include <vector>
#include <set>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> to_sum;
        int lowest_number = -99999999999;
        // We start with a very low number, so we can compare it

        for (auto num : nums) {
            if (num >= 0) {
                to_sum.insert(num);
            }
            else {
                if (num >= lowest_number) {
                    lowest_number = num;
                    // Here is the comparison for example
                    // If we have [-17, -15]
                    // -15 > -17 therefore lowest_number = -15
                    // Being closer to zero gives a higher sum
                }
            }
        }

        // If the set size is zero, it means we don't have
        // Any zero or positive numbers, therefore we only add
        // The biggest negative one
        if (to_sum.size() == 0) {
            to_sum.insert(lowest_number);
        }

        int sum = 0;
        sum = accumulate(to_sum.begin(), to_sum.end(), 0);
        return sum;
    }
};
