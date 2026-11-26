class Solution {
public:
    bool canAliceWin(int n) {
        int val = 10;
        int turn = 1;
        while (n != 0) {
            if (n < val) return turn != 1;
            n -= val;
            val--;
            turn ^= 1;
        }
        return turn == 0;
    }
};
