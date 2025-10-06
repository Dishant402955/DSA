
class Solution {

public:
    bool check(vector<vector<int>>& grid, int t) {
        int n = grid.size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        vector<vector<int>> vis(n, vector<int>(n, 0));

        vis[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});

        int level = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (x == n - 1 && y == n - 1) {
                    return true;
                }

                for (int k = 0; k < 4; k++) {
                    int nx = dx[k] + x;
                    int ny = dy[k] + y;

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                        !vis[nx][ny] && grid[nx][ny] <= t) {
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }

            level++;
        }

        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {

        int low = grid[0][0];

        int high = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                high =max(high,grid[i][j]);
            }
        }
        
        int ans = high;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (check(grid, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
