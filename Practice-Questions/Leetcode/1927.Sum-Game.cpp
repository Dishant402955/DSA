class Solution {
public:
    bool sumGame(string num) {
        
        int n = num.size();
        int half = n / 2;

        int sum1 = 0, sum2 = 0;
        int q1 = 0, q2 = 0;

        // First half
        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                q1++;
            else
                sum1 += num[i] - '0';
        }

        // Second half
        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                q2++;
            else
                sum2 += num[i] - '0';
        }

        // Odd number of '?' -> Alice wins
        if ((q1 + q2) % 2 == 1)
            return true;

        // Bob wins only in this exact balancing case
        return sum1 - sum2 != 9 * (q2 - q1) / 2;
    }
};
