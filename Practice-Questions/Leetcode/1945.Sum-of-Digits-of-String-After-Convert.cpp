class Solution {
public:
    int getLucky(string s, int k) {
        
        string m;

        for ( char i : s ){
            int a = i - 'a' + 1;
            m += to_string(a);
        }

        int sum;

        for ( int i = 1; i <= k; i++){

            sum = 0;
            for ( char j : m){
              sum += j - '0' ;
            }

            m.erase();
            m += to_string(sum);

        }

        return sum;

    }
};