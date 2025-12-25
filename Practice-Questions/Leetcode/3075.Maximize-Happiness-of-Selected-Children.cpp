class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        reverse(happiness.begin(),happiness.end());
        long long total = 0;
        for(int i = 0;i<k;i++){
            total += max(0,happiness[i]-i); //to avoid negative
        } 
        return total;
    }
};
