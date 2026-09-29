class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {1, 0};
        int dy[] = {0, 1};
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<vector<int>>> vis(
            m, vector<vector<int>>(n, vector<int>(m + n, 0)));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        vis[0][0][1] = 1;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int r = p.first.first;
            int c = p.first.second;
            int cnt = p.second;
            if (r == m - 1 && c == n - 1 && cnt == 0)
                return true;
            for (int k = 0; k < 2; k++) {
                int nr = dx[k] + r;
                int nc = dy[k] + c;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newcnt = cnt;

                    if (grid[nr][nc] == '(')
                        newcnt++;
                    else
                        newcnt--;

                    if (newcnt < 0)
                        continue;

                    if (!vis[nr][nc][newcnt]) {
                        vis[nr][nc][newcnt] = 1;
                        q.push({{nr, nc}, newcnt});
                    }
                }
            }
        }
        return false;
    }
};
