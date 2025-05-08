class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int rows = moveTime.size();
        int cols = moveTime[0].size();

        vector<vector<int>> timeMatrix(rows, vector<int>(cols, INT_MAX));
        timeMatrix[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            auto topElement = pq.top();
            pq.pop();

            int time = topElement.first;
            int xC = topElement.second.first;
            int yC = topElement.second.second;

            if (xC == rows - 1 && yC == cols - 1) {
                return timeMatrix[xC][yC];
            }

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int newX = xC + dx[i];
                int newY = yC + dy[i];

                if (newX >= 0 && newY >= 0 && newX < rows && newY < cols && timeMatrix[newX][newY] == INT_MAX) {
                    int timeToMove = 0;
                    if ((newX + newY) & 1) {
                        timeToMove = 1 + max(moveTime[newX][newY], time);
                    }
                    else {
                        timeToMove = 2 + max(moveTime[newX][newY], time);
                    }
                    timeMatrix[newX][newY] = timeToMove;
                    pq.push({timeToMove, {newX, newY}});
                }
            }
        }
        return 0;
    }
};