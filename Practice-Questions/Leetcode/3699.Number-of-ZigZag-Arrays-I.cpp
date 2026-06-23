#include <cstdint>
#include <numeric>


using u32 = uint32_t;

inline static constexpr u32 kMOD = 1'000'000'007;

class Solution
{
public:
    inline static u32 dp[2][2000];

    [[gnu::always_inline, nodiscard]]
    static constexpr u32 modAdd(u32 x, u32 y) noexcept
    {
        x += y;
        return x -= kMOD & -u32{x >= kMOD};
    }

    [[gnu::always_inline, nodiscard]]
    u32 zigZagArrays(const u32 n, u32 l, u32 r) noexcept
    {
        return impl(n, r + 1u - l);
    }

    static u32 impl(const u32 n, const u32 m) noexcept
    {
        [[assume(n > 2)]];
        [[assume(m > 1)]];
        [[assume(m < 2000)]];

        bool t = 0;
        std::iota(dp[t], dp[t] + m, 0u);

        for (u32 i = 2; i != n; ++i)
        {
            t = !t;
            u32 s{};
            for (u32 j = 0, k = m - 1; j != m; ++j, --k)
            {
                dp[t][j] = s;
                s = modAdd(s, dp[!t][k]);
            }
        }

        u32 x{};
        for (u32 j = 0; j != m; ++j) x = modAdd(x, dp[t][j]);

        return (x * 2u) % kMOD;
    }
};
