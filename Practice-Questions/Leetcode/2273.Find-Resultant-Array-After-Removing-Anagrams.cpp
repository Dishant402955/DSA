class Solution
{
public:
    using u8 = uint8_t;
    using u64 = uint64_t;

    static constexpr void getCounters(
        std::string_view s,
        const std::span<u64, 4>& counters) noexcept
    {
        std::ranges::fill(counters, 0);
        const std::span<u8, 32> v{
            reinterpret_cast<u8*>(&counters[0]),  // NOLINT
            32,
        };
        for (char c : s) ++v[static_cast<u8>(c - 'a')];
    }

    std::vector<std::string> removeAnagrams(
        std::vector<std::string>& words) noexcept
    {
        std::array<u64, 8> arr{};
        auto a = std::span{arr}.first<4>();
        auto b = std::span{arr}.last<4>();

        u8 n = 0;
        for (auto& word : words)
        {
            getCounters(word, b);
            if (!std::ranges::equal(a, b))
            {
                // The string is small, so
                // no need to move (SSO ftw)
                words[n++] = word;
                std::swap(a, b);
            }
        }

        words.resize(n);
        return std::move(words);
    }
};
