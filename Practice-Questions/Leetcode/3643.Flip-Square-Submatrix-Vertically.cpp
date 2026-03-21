class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int sc = y;
        int ec = y + k - 1;
        int sr = x;
        int er = x + k - 1;
        for (int j = sc; j <= ec; j++) {
            for (int i = 0; i < k / 2; i++) {
                swap(grid[sr+i][j], grid[sr+k-i-1][j]);
            }
        }
        return grid;
    }
};
