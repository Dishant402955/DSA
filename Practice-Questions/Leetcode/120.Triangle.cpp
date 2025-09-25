class Solution
{
public:
    using u8 = uint8_t;
    [[nodiscard]] static constexpr int minimumTotal(
        std::vector<std::vector<int>>& triangle) noexcept
    {
        for (u8 y = (triangle.size() - 1) & 0xFF; y--;)
        {
            for (u8 x = triangle[y].size() & 0xFF; x--;)
            {
                triangle[y][x] +=
                    std::min(triangle[y + 1][x], triangle[y + 1][x + 1]);
            }
        }
        return triangle[0][0];
    }
};
