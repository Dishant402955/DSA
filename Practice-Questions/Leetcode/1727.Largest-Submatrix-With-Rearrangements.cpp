class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        vector<int> h(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) h[j]++;
                else h[j] = 0;
            }
            vector<int> sh = h;
            sort(sh.rbegin(), sh.rend());
            for (int j = 0; j < n; j++) {
                if (sh[j] == 0) break;
                maxArea = max(maxArea, sh[j] * (j + 1));
            }
        }
        return maxArea;
    }
};
