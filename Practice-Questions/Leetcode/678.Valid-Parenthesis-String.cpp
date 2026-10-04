class Solution {
public:
    bool checkValidString(string s) {
        bitset<101> mask;
        mask.set(0);

        for (char ch : s) {
            if (ch == '(') {
                mask <<= 1;
            } else if (ch == ')') {
                mask >>= 1;
            } else {
                mask = (mask << 1) | mask | (mask >> 1);
            }
        }

        return mask.test(0);
    }
};
