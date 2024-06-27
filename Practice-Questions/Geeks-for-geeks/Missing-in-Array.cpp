// the approach will be written soon

class Solution {

  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr){

        bool temp[n+1] = {0};
    
        for(int i = 0 ; i < n-1 ; i++){
            temp[arr[i]] = 1 ;
        }
    
        for(int i = 1 ; i <= n ; i++){
            if( temp[i] == 0 )   return i;
        }
      
    }

};