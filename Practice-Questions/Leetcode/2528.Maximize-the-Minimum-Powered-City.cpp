class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> prefix(n + 1, 0), power(n, 0);

        // Step 1: Compute prefix sum of stations
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stations[i];
        }

        // Step 2: Compute initial power for each city
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            power[i] = prefix[right + 1] - prefix[left];
        }

        // Helper function to check if we can make all powers >= mid
        auto can = [&](long long mid) {
            vector<long long> added(n, 0);
            long long extra = 0;
            long long remaining = k;

            for (int i = 0; i < n; i++) {
                if (i - r - 1 >= 0) extra -= added[i - r - 1];
                long long curr = power[i] + extra;

                if (curr < mid) {
                    long long need = mid - curr;
                    if (need > remaining) return false;
                    remaining -= need;
                    added[min(n - 1, i + r)] += need;
                    extra += need;
                }
            }
            return true;
        };

        // Step 3: Binary search on answer
        long long low = 0, high = 1e15, ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
