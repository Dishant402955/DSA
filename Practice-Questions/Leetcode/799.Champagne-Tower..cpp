class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glasses;
        for (int i = 1; i <= 100; i++) {
            vector<double> glass(i, 0.0);
            glasses.push_back(glass);
        }

        glasses[0][0] = poured;

        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (glasses[i][j] > 1.0) {
                    double divided = (glasses[i][j] - 1) / 2;
                    glasses[i + 1][j] += divided;
                    glasses[i + 1][j + 1] += divided;
                    glasses[i][j] = 1.0;
                }
            }
        }
        return min(1.0, glasses[query_row][query_glass]);
    }
};
