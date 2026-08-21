#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        int n = coins.size();
        
        // Binary search range boundaries
        long long low = 1;
        long long high = 1LL * (*std::min_element(coins.begin(), coins.end())) * k;
        long long ans = high;
        
        // Precompute LCMs for all subsets to optimize the binary search loop
        // Each element stores: {lcm_value, number_of_elements_in_subset}
        std::vector<std::pair<long long, int>> subsets;
        
        // 1 << n represents 2^n total subsets
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int elements_count = 0;
            bool overflow = false;
            
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    elements_count++;
                    // Calculate LCM: (a * b) / gcd(a, b)
                    long long g = std::gcd(current_lcm, (long long)coins[i]);
                    
                    // Prevent potential overflow during calculations
                    if (current_lcm > (high * g) / coins[i]) {
                        overflow = true;
                        break;
                    }
                    current_lcm = (current_lcm / g) * coins[i];
                }
            }
            
            if (!overflow) {
                subsets.push_back({current_lcm, elements_count});
            }
        }
        
        // Helper lambda function to count valid multiples <= mid using PIE
        auto countMultiples = [&](long long mid) {
            long long total_count = 0;
            for (const auto& [lcm_val, count] : subsets) {
                if (count % 2 == 1) {
                    total_count += mid / lcm_val; // Odd size: add
                } else {
                    total_count -= mid / lcm_val; // Even size: subtract
                }
            }
            return total_count;
        };
        
        // Perform Binary Search
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (countMultiples(mid) >= k) {
                ans = mid;        // Candidate answer found, try to find a smaller one
                high = mid - 1;
            } else {
                low = mid + 1;    // Not enough multiples, look in the higher half
            }
        }
        
        return ans;
    }
};
