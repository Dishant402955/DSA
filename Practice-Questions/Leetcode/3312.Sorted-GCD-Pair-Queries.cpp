class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1);
        for (int x : nums)
            freq[x]++;

        vector<long long> cntMul(mx + 1);

        for (int g = 1; g <= mx; g++)
            for (int j = g; j <= mx; j += g)
                cntMul[g] += freq[j];

        vector<long long> exact(mx + 1);

        for (int g = mx; g >= 1; g--) {
            long long c = cntMul[g];
            exact[g] = c * (c - 1) / 2;

            for (int j = g + g; j <= mx; j += g)
                exact[g] -= exact[j];
        }

        vector<long long> prefix(mx + 1);

        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long q : queries) {
            int lo = 1, hi = mx;

            while (lo < hi) {
                int mid = (lo + hi) >> 1;

                if (prefix[mid] > q)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            ans.push_back(lo);
        }

        return ans;
    }
};
