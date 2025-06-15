class Solution {
public:
    void replace_all(std::vector<int>& vec, int old_value, int new_value) {
        for (int& val : vec) {
            if (val == old_value) {
                val = new_value;
            }
        }
    }

    int maxDiff(int num) {
        vector<int> digits;
        if (num == 0)
            digits.push_back(0);
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());

        vector<int> maxDigits(digits.begin(), digits.end());
        vector<int> minDigits(digits.begin(), digits.end());

        int maxNum = 0, minNum = 0;

        // Replace first non-9 digit with 9 in maxDigits
        for (int i = 0; i < maxDigits.size(); ++i) {
            if (maxDigits[i] != 9) {
                replace_all(maxDigits, maxDigits[i], 9);
                break;
            }
        }

        // Replace digits in minDigits to minimize the number
        for (int i = 0; i < minDigits.size(); ++i) {
            if (minDigits[i] != 1 && i == 0) {
                replace_all(minDigits, minDigits[i], 1);
                break;
            } else if (minDigits[i] != 0 && minDigits[i] != 1) {
                replace_all(minDigits, minDigits[i], 0);
                break;
            }
        }

        for (int d : maxDigits)
            maxNum = maxNum * 10 + d;
        for (int d : minDigits)
            minNum = minNum * 10 + d;

        return maxNum - minNum;
    }
};
