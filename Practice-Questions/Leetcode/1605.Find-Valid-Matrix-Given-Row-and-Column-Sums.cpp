class Solution {
    
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

        int m = rowSum.size(), n = colSum.size();

        vector<vector<int>> res(m, vector<int>(n));

        for (int i = 0, j = 0; i < m && j < n;){

            res[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= res[i][j];
            colSum[j] -= res[i][j];
            rowSum[i] == 0 ? i++ : j++;

        }

        return res;

    }
};