class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<unordered_set<int>> dirs = {
            {}, {0, 1}, {2, 3}, {0, 3}, {1, 3}, {0, 2}, {1, 2}
        };
        int moves[4][4] = {
            {0, -1, 0, 1}, 
            {0, 1, 1, 0},  
            {-1, 0, 2, 3}, 
            {1, 0, 3, 2} 
        };

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (r == rows - 1 && c == cols - 1) 
                return true;

            for (auto& m : moves) {
                int nr = r + m[0], nc = c + m[1];
                int outDir = m[2], inDir = m[3];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                    if (dirs[grid[r][c]].count(outDir) && dirs[grid[nr][nc]].count(inDir)) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
};
