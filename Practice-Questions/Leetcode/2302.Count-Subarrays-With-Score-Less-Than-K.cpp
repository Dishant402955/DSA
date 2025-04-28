class Solution {
public:
    static long countSubarrays(const vector<int>& a, const long k) {
        const int n = a.size();
        long count = 0;
        long s = a[0];
        for (int i = 0, w = 1;;) {
            if (s * w < k) {
                count += w++;
                if (++i == n) break;
                s += a[i];
            } else {
                s -= a[i + 1 - w--];
            }
        }
        return count;
    }
};