class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> best(n, vector<int>(m, 0));
        priority_queue<tuple<int, int, int>> pq;
        if(grid[0][0] == 1) {
            health--;
        }
        best[0][0] = health;
        // health, row, col
        pq.push({health, 0, 0});
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        while(!pq.empty()) {
            auto[presentHealth, row, col] = pq.top();
            pq.pop();
            if(presentHealth < best[row][col]) continue;
            for(int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                int newHealth = presentHealth;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m ) {
                    if(grid[nrow][ncol] == 1) {
                        newHealth--;
                    }
                    if(newHealth > best[nrow][ncol] && newHealth >= 1) {
                        pq.push({newHealth, nrow, ncol});
                        best[nrow][ncol] = newHealth;
                    }
                }
            }
        }
        if(best[n - 1][m - 1] >= 1) return true;
        else return false;
    }
};
