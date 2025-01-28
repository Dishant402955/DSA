class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<bool>>& vis) {
        // Base case: Out of bounds or invalid cell
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || vis[i][j]) {
            return 0;
        }

        // Mark the cell as visited
        vis[i][j] = true;

        // Start with the current cell's fish count
        int total = grid[i][j];

        // Explore all 4 directions
        total += dfs(grid, i - 1, j, m, n, vis); // Up
        total += dfs(grid, i + 1, j, m, n, vis); // Down
        total += dfs(grid, i, j - 1, m, n, vis); // Left
        total += dfs(grid, i, j + 1, m, n, vis); // Right

        return total;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false)); // Visited array

        // Iterate over all cells in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) { // Start DFS for each new component
                    ans = max(ans, dfs(grid, i, j, m, n, vis));
                }
            }
        }

        return ans;
    }
};