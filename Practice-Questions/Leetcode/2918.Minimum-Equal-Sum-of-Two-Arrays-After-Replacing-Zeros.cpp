class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), (long long)0);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), (long long)0);
        long long x1 = 0, x2 = 0;
        
        for (int i : nums1) if (i == 0) x1++;
        for (int i : nums2) if (i == 0) x2++;
        
        long long diff = abs(sum1 - sum2);

        if (sum1 == sum2 && x1 == x2) return sum1 + x1;
        
        if ((!x1 && diff < x2) || (!x2 && diff < x1) || (sum1 < sum2 && !x1) || (sum1 > sum2 && !x2) || (sum1 == sum2 && (!x1 || !x2))) 
            return -1;

        if (sum1 == sum2) {
            return (x1 > x2) ? x1 + sum1 : x2 + sum2;
        }

        return (sum1 + x1 > sum2 + x2) ? sum1 + x1 : sum2 + x2;
    }
};