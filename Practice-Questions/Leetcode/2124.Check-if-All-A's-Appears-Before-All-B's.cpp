class Solution {
public:
    bool checkString(string s) {
        int f=0;

        for(auto c:s){
            if(c=='b') f=1;

            if(f and c=='a') return 0;
        }
        return 1;
    }
};
