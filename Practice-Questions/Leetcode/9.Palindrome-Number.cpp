class Solution {
public:
    bool isPalindrome(long x) {

        if( x < 0){
            return 0;
        }else{
            long remainder , temp = x , reverse = 0;
            while(temp != 0){
                remainder = temp % 10 ;
                temp = temp / 10 ;
                reverse = reverse *10 + remainder ; 
            }
            if(reverse==x){
                return 1;
            }else{
                return 0;
            }
        }
    }
};