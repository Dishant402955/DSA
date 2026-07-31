class Solution {
public:
  static int minimumPushes(
    const std::string_view Str_
  ) {
    // If the string is less than or equal to 8, we require the string's size number of keypresses, always,
    // no matter if the characters are unique or repeating, or all are same.
    if (Str_.size() <= 8) {
      return Str_.size();
    }

    // Stores the frequency of each character.
    std::array<int, 26> freq{};

    for (const char ch : Str_) {
      ++freq[(std::size_t)(ch) - 'a'];
    }

    std::sort(freq.begin(), freq.end());

    // Stores the number of loops in 2-9.
    unsigned char loops{};

    // Stores the current number being filled.
    unsigned char num{ 2 };

    // The accumulator.
    int res{};

    for (std::ptrdiff_t i{ 25 }; i >= 0; --i) {
      // The first character with frequency 0 is found. All subsequent characters will have 0 as well.
      // Break the loop.
      if (!freq[i]) {
        break;
      }

      // Add to the accumulator.
      res += freq[i] * (int)(loops + 1);

      if (num == 9) {
        ++loops;
        num = 2;
      } else {
        ++num;
      }
    }

    return res;
  }
};
