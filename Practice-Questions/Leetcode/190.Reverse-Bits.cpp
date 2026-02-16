class Solution {
public:
    uint32_t reverseBits(uint32_t n) { return rev(n, 32); }

private:
    uint32_t rev(uint32_t v, int len) {
        if (len == 1) return v & 1u;

        int half = len >> 1;
        uint32_t mask = (1u << half) - 1u;
        uint32_t lo = v & mask;
        uint32_t hi = v >> half;

        uint32_t rlo = rev(lo, half);
        uint32_t rhi = rev(hi, half);

        return (rlo << half) | rhi;
    }
};
