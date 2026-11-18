class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int flip = 0;
        int i = 0;
        while(i < n){
            int countZero = 0;
            int countOne = 0;
            for(int count = 1; count<=2; count++){
                if(s[i] == '0') countZero++;
                else countOne++;
                i++;
            }
            if(countZero == 0) continue;
            if(countOne == 0) continue;
            flip++;
        }
        return flip;
    }
};
