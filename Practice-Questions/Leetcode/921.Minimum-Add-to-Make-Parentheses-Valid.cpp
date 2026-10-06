class Solution {
public:
    int minAddToMakeValid(string s) {

        int a = 0; // unmatched '('
        int b = 0; // unmatched ')'

        for (char ch : s) {

            if (ch == '(') {

                a++;

            } else if (a > 0) {

                a--;

            } else {

                b++;
            }
        }

        return a + b;
    }
};
