class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        // Add all boundary cells to the min-heap
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int waterTrapped = 0;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // down, up, right, left

        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();
            int x = cell.first;
            int y = cell.second;

            // Explore neighbors
            for (auto& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                // Check bounds
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                    // If the neighbor is lower than the current height, it can trap water
                    if (heightMap[newX][newY] < height) {
                        waterTrapped += height - heightMap[newX][newY];
                    }
                    // Push the maximum height to the heap
                    minHeap.push({max(height, heightMap[newX][newY]), {newX, newY}});
                    visited[newX][newY] = true;
                }
            }
        }

        return waterTrapped;
    }
};