class Solution {
public:
    int rotatedDigits(int n) {
        // cnt will store the count of the desired numbers
        int cnt = 0;
        // exploring all the numbers from [1 , n]
        for(int i = 1 ; i <= n ; i ++){
            // curr number -> check
            int check = i;
            // valid is for those numbers whose all digits can be rotated
            bool valid = true;
            // changed is if the digit changes on rotation 
            bool changed = false;
            while(check > 0 && valid){
                // see the current digit
                int digit = check % 10;
                // if the digit can not be rotated then this number is not valid
                if(digit == 3 ||  digit == 4 || digit == 7) valid = false;
                // if the digit's value is changed on rotation then it the number becomes "changed"
                else if(digit == 2 || digit == 5 || digit == 6 || digit == 9) changed = true;
                // division by 10 to go to the next digit
                check /= 10;
            }
            // if all digits are valid and the number's value is changed on rotation then it will be counted
            if(valid && changed) cnt ++;
        }
        // returning the count
        return cnt;
    }
};
