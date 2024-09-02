class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        long long int sum = 0;

        for ( int i : chalk){
          sum += i;
        }

        while( k >= 0){
          if ( k - sum < 0)
            break;

          k -= sum;
        }

        int i = 0;

        while( k>=0 ){

          for ( i = 0; i < chalk.size(); i++){
              if( k - chalk[i] < 0){
                return i % chalk.size();
              }
              k = k - chalk[i];
          }

        }

        return i % chalk.size();
    }
};