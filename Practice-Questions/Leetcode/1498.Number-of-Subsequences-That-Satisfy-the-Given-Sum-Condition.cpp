class Solution {
public:
    long long fpow(long long num, long long power, long long mod = 1e9+7)
    {
        if (power == 0)
            return 1;
        if (power == 1)
            return num % mod;
        long long ans = fpow(num, power / 2, mod);
        ans = ((ans % mod) * (ans % mod)) % mod;
        if (power & 1)
            ans = ((ans % mod) * (num % mod)) % mod;
        return ans % mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        const long long mod = 1e9 + 7;
        long long n = nums.size();
        sort(nums.begin() , nums.end());
        long long ans = 0;
        for(long long i = 0 ; i < n ; i++)
        {
            long long mn = nums[i];
            // auto it = lower_bound(nums.begin() , nums.end() , target - mn);
            // if(it == nums.end())continue;
            auto it = upper_bound(nums.begin() , nums.end() , target - mn);
            it--;
            long long pos = it - nums.begin();
            long long len = pos - i;
            if(len < 0) continue;
            ans = (ans + (fpow(2 , len) % mod)) % mod;
            ans %= mod;
        }
        return ans % mod;
    }
};
