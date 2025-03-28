class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& qu) {
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater <pair<int , pair<int , int>>>> pq;
        vector<pair <int , int>> q;
        int z = 0;
        for (int i : qu) q.push_back({i , z++});
        sort (q.begin(),q.end());
        int sum = 0;
        int j = 0;
        vector<int>v(q.size(),0);
        pq.push({grid[0][0] , {0 , 0}});
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {1 , 0 , 0 , -1};
        int dy[4] = {0 , 1 , -1 , 0};
        vector<vector<int>>vis(n , vector<int>(m , 0));
        vis[0][0]=1;
        while (!pq.empty()) {
            int zz = pq.size();
            auto node = pq.top();
            int val = node.first;
            int r = node.second.first;
            int c = node.second.second;
            pq.pop();
            if (grid[r][c] < q[j].first)
            sum += 1;
            else {
                while (j < q.size() && q[j].first <= grid[r][c]) {
                    v[j] = sum;
                    j++;
                }
                sum += 1;
                if (j == q.size()) break;
            }
            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && vis[nr][nc] == 0) {
                    pq.push({grid[nr][nc] , {nr , nc}});
                    vis[nr][nc]=1;
                }
            }
        }
        while (j < q.size()) {
            v[j] = sum;
            j++;
        }
        vector<int>ans(q.size());
        for (int i = 0; i < v.size(); i++) {
            ans[q[i].second] = v[i];
        }
        return ans;
    }
};