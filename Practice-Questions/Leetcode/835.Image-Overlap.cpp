class Solution {
public:
    int countOverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2,
                      int rowOff, int colOff) {
        int n = img1.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = i + rowOff;
                int y = j + colOff;

                if (x < 0 || x >= n || y < 0 || y >= n)
                    continue;

                if (img1[i][j] == 1 && img2[x][y] == 1)
                    count++;
            }
        }

        return count;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        for (int row = -n + 1; row < n; row++) {
            for (int col = -n + 1; col < n; col++) {
                ans = max(ans, countOverlaps(img1, img2, row, col));
            }
        }

        return ans;
    }
};
