class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total_sum = 0;
        for (int b :batteries) total_sum += b;
        long long low = 0;
        long long high =total_sum /n + 1; // Upper bound
        // Binary Search for the Maximum Time
        while (low <high) {
            long long mid = low +(high -low + 1) / 2;
            long long actual_power = 0;
            for (int b : batteries) {
                // A battery can only contribute at most 'mid' minutes
                actual_power += min((long long)b,mid);
            }
            // Check if we have enough power to run N computers for 'mid' minutes
            if (actual_power>= n * mid) {
                low = mid; // Possible, try higher
            } else {
                high= mid - 1; // Not possible, try lower
            }
        }
        return low;
    }
};
