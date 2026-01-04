class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long total = 0;
        for (int n : nums) {
            int cnt = 0;
            int s = 0;
            int root = (int)sqrt(n);
            for (int i = 1; i <= root; ++i) {
                if (n % i == 0) {
                    int j = n / i;
                    if (i == j) {
                        cnt += 1;
                        s += i;
                    } else {
                        cnt += 2;
                        s += i + j;
                    }
                    if (cnt > 4) break;
                }
            }
            if (cnt == 4) total += s;
        }
        return (int)total;
    }
};
