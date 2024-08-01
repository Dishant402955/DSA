class Solution {
public:
    int countSeniors(vector<string>& d) {
        int ans = 0;
        for(int i = 0; i < d.size(); i++){
            int age;
            char ch = d[i][11];
            age = ch - '0';
            ch = d[i][12];
            age = age*10 + (ch - '0');

            if(age > 60)
                ans++;
        }

        return ans;
    }
};