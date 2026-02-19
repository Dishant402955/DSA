class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 1, cnt = 0;
        for(int i = 1;i<s.size();i++){
            if(s[i] == s[i-1])
                curr++;
            else{
                prev = curr;
                curr = 1;
            }
            if(curr <= prev)
                cnt++;
        }
        return cnt;
    }
};
