#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> ost;
        ost[0] = 1;
        int prefix = 0;
        long long ans = 0;
        for (int x : nums) {
            if (x % modulo == k) prefix = (prefix + 1) % modulo;
            int need = (prefix - k) % modulo;
            if (need < 0) need += modulo;
            ans += ost[need];
            ost[prefix]++;
        }
        return ans;
    }
};