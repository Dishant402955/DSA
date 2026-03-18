class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // Build prefix sum for first column
        for(int i = 1; i < n; i++) 
            grid[i][0] += grid[i-1][0];

        // Build prefix sum for first row
        for(int j = 1; j < m; j++) 
            grid[0][j] += grid[0][j-1];

        // Build full 2D prefix sum
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            }
        }

        // Count valid submatrices
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] <= k) cnt++;
            }
        }

        return cnt;
    }
};
