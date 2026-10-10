class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        vector<long long> d(n);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            d[i] = abs(nums1[i] - nums2[i]);
            total += d[i];
        }

        if (total <= k)
            return 0;

        sort(d.rbegin(), d.rend());
        d.push_back(0);

        for (int i = 1; i <= n; i++) {
            long long cost = (d[i - 1] - d[i]) * i;

            if (cost > k) {
                long long q = k / i;
                long long r = k % i;
                long long hi = d[i - 1] - q;

                long long res = hi * hi * (i - r)
                              + (hi - 1) * (hi - 1) * r;

                for (int j = i; j < n; j++)
                    res += d[j] * d[j];

                return res;
            }

            k -= cost;
        }

        return 0;
    }
};
