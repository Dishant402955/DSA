class Solution {
public:
    using u32 = uint32_t;
    static constexpr u32 m = 100'000;
    inline static u32 f[m + 1];
    u32 maximumElementAfterDecrementingAndRearranging(
        const vector<int>& nums) noexcept {
        u32 a = m, b = 0, v = 0;
        for (u32 x : nums) {
            x = min(x, m);
            a = min(a, x);
            b = max(b, x);
            ++f[x];
        }
        [[assume(b <= m)]];
        while (a <= b) {
            v += min(a - v, f[a]);
            f[a++] = 0;
        }
        return v;
    }
};
