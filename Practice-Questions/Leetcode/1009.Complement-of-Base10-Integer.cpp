class Solution {
public:
    int bitwiseComplement(int n) {
         int temp = n;
    int mask=0;
    do{
        mask= (mask<<1) | 1 ;
        temp = temp >> 1 ;
    }while(temp!=0);
     int answer = (~n) & mask;
   return answer;
    }
};