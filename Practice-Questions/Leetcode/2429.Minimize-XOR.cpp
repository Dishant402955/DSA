
class Solution {

public:
    int minimizeXor(int num1, int num2) {
        int setBits2 = countSetBits(num2);
        // first turn off largest bits from num1
        int ans = 0, fsb = firstSetBit(num1), largest = fsb;
        while (setBits2 && largest >= 0) {
            if (num1 & (1 << largest)) {
                ans ^= (1 << largest);
                setBits2--;
            }
            largest--;
        }
        //if there are still left bits to set, try to set them from the least significant bit i.e. i = 0
        int i = 0;
        while (setBits2) {
            if ((ans & (1 << i)) == 0) {
                ans ^= (1 << i);
                setBits2--;
            }
            i++;
        }

        return ans;
    }

private:
    int countSetBits(int x) {
        int i = 0, ans = 0;
        while (i < 31) {
            if (x & (1 << i)) ans++;
            i++;
        }
        return ans;
    }
    int firstSetBit(int x) {
        int i = 0, ans = 0;
        while (i < 31) {
            if (x & (1 << i)) ans = i;
            i++;
        }
        return ans;
    }
};