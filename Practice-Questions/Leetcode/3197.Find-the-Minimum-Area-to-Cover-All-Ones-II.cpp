class Solution {
public:
    vector<vector<int>> rotateMatrix(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rotatedMatrix(n, vector<int>(m));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rotatedMatrix[n - j - 1][i] = grid[i][j];
            }
        }

        return rotatedMatrix;
    }

    int findMinimumArea(int rowStart, int rowEnd, int colStart, int colEnd, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        int minRow = 1e9, maxRow = -1, minCol = 1e9, maxCol = -1;

        for(int i = rowStart; i < rowEnd; i++){
            for(int j = colStart; j < colEnd; j++){
                if(grid[i][j] == 1){
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);

                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        if(maxRow == -1) return 0;
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    int solve(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int res = 1e9;
        
        // Case 1,2 without rotation
        // Case 4,5 with rotation

        // where row split starts
        for(int rowSplit = 1; rowSplit < m; rowSplit++){
            // where column split starts
            for(int colSplit = 1; colSplit < n; colSplit++){
                // Case 1, 4
                int topBoxFull = findMinimumArea(0, rowSplit, 0, n, grid);
                int bottomBoxFirst = findMinimumArea(rowSplit, m, 0, colSplit, grid);
                int bottomBoxSecond = findMinimumArea(rowSplit, m, colSplit, n, grid);
                
                res = min(res, topBoxFull + bottomBoxFirst + bottomBoxSecond);

                // Case 2,5
                int topBoxFirst = findMinimumArea(0, rowSplit, 0, colSplit, grid);
                int topBoxSecond = findMinimumArea(0, rowSplit, colSplit, n, grid);
                int bottomBox = findMinimumArea(rowSplit, m, 0, n, grid);

                res = min(res, topBoxFirst + topBoxSecond + bottomBox);
            }
        }

        // Case 3 without rotation
        // Case 6 with rotation

        for(int firstSplit = 1; firstSplit < m - 1; firstSplit++){
            for(int secondSplit = firstSplit + 1; secondSplit < m; secondSplit++){
                int topBox = findMinimumArea(0, firstSplit, 0, n, grid);
                int middleBox = findMinimumArea(firstSplit, secondSplit, 0, n, grid);
                int bottomBox = findMinimumArea(secondSplit, m, 0, n, grid);

                res = min(res, topBox + middleBox + bottomBox);
            }
        }
        
        return res;
    }

    int minimumSum(vector<vector<int>>& grid) {
        /* 
            Refer above image for cases.
            Case 1 -> Top box , bottom box split 
            Case 2 -> Top box split, bottom box
            Case 3 -> Top Split, Middle Split, Bottom Split

            Case 4 -> Rotated Case 1
            Case 5 -> Rotated Case 2
            Case 6 -> Rotated Case 3
        */

        int res = solve(grid);

        vector<vector<int>> rotatedGrid = rotateMatrix(grid);

        res = min(res, solve(rotatedGrid));

        return res;
    }
};
