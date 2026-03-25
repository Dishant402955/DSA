class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        vector<long long> rs(n, 0), cs(m, 0);

        for(int i = 0; i < n; i++){
            long long sum = 0;
            for(int j = 0; j < m; j++){
                sum += grid[i][j];
                cs[j] += grid[i][j]; // column sum
            }
            rs[i] = (i > 0 ? rs[i-1] : 0) + sum; // row prefix sum
        }

        for(int i = 1; i < m; i++){
            cs[i] += cs[i-1]; // column prefix sum
        }

        for(int i = 0; i < n-1; i++){
            if(rs[i] == rs[n-1] - rs[i]) return true;
        }

        for(int i = 0; i < m-1; i++){
            if(cs[i] == cs[m-1] - cs[i]) return true;
        }

        return false;
    }
};
