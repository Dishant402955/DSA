class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            int num = 10*min(dominoes[i][0],dominoes[i][1]) + max(dominoes[i][0],dominoes[i][1]);
            mp[num]++;
        }

        int count = 0;

        for(auto p : mp) {
            if(p.second > 1) {
                count += (p.second*(p.second-1))/2;
            }
        }

        return count;
    }
};