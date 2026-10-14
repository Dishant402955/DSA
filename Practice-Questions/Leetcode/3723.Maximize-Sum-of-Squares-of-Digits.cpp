class Solution {
public:
    string maxSumOfSquares(int dcnt, int dsum) {

        if(dsum > 9 * dcnt) return "";

        string ans;
        while(dsum > 0) {
            int k = min(9, dsum);
            ans += k + '0';
            dsum -= k;
        }
        ans.resize(dcnt, '0');
        return ans;
    }
};
