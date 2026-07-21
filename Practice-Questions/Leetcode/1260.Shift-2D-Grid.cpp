class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int m=grid.size(), n=grid[0].size();
        auto [q, r]=div(k, n);
        q%=m;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            int i1=i+q+1; 
            for(int j=0; j<n; j++){
                bool minus1=(j+r<n); 
                int j0=j+r;
                j0-=(j0>=n)?n:0;
                int i0=i1-minus1;
                i0-=(i0>=m)?m:0;
                ans[i0][j0]=grid[i][j];
            }
        }
        return ans;
    }
};
