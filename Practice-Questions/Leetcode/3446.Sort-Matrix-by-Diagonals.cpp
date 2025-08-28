class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        auto reverse = [&](vector<int>& arr) {
            int i = 0, j = arr.size() - 1;
            while (i < j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        };

        auto sortDiagonal = [&](int row, int col, bool increasing) {
            int len = min(rows - row, cols - col);
            vector<int> diagonal(len);

            for (int i = 0; i < len; i++) {
                diagonal[i] = mat[row + i][col + i];
            }

            sort(diagonal.begin(), diagonal.end());
            if (!increasing) reverse(diagonal);

            for (int i = 0; i < len; i++) {
                mat[row + i][col + i] = diagonal[i];
            }
        };

        for (int row = 0; row < rows; row++) {
            sortDiagonal(row, 0, false); // non-increasing
        }

        for (int col = 1; col < cols; col++) {
            sortDiagonal(0, col, true); // non-decreasing
        }

        return mat;
    }
};
