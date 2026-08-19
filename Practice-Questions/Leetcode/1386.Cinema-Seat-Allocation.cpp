class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>>mpp;
        for(auto p : reservedSeats){
            mpp[p[0]].push_back(p[1]);
        }
        int ans = (n-mpp.size())*2;
        for(auto it : mpp){
            unordered_map<int, int>temp;
            for(auto num : it.second){
                temp[num]++;
            }
            if(!temp[2] && !temp[3] && !temp[4] && !temp[5]){
                temp[4]++;
                temp[5]++; ans++;
            }
            if(!temp[4] && !temp[5] && !temp[6] && !temp[7]){
                temp[6]++;
                temp[7]++;
                 ans++;
            }
            if(!temp[6] && !temp[7] && !temp[8] && !temp[9]) ans++;

        }
        return ans;
    }
};
