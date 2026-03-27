class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size(), nextInd;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i % 2 == 0){
                    nextInd = ((j - k) % n + n) % n;
                    if(j == nextInd)
                        break;
                    if(mat[i][j] != mat[i][nextInd])
                        return false;
                }
                else{
                    nextInd = (j + k) % n;
                    if(j == nextInd)
                        break;
                    if(mat[i][j] != mat[i][nextInd])
                        return false;
                }
            }
        }
        return true;
    }
};
