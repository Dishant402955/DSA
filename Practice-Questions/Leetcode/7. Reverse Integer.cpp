class Solution {
public:
    int reverse(int x) {
      int helper = x;

      if(helper == INT_MIN || helper == 0){
        return 0;
      }

      if(helper < 0){
        helper *= -1;
      }


      while(helper && helper%10 == 0){
        helper /= 10;
      }

      int ans = 0;

      while(helper){

        if(ans > INT_MAX/10){
          return 0;
        }

        ans = ans*10 + helper%10;
        helper /= 10; 
      }

      if(x < 0){
        ans *= -1;
      }

      return ans;
    }
};