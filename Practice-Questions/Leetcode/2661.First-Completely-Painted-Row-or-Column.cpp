#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> map;

        int m = mat.size();     // Number of rows
        int n = mat[0].size();  // Number of columns

        // Populate the map with matrix elements and their coordinates
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[mat[i][j]] = {i, j};
            }
        }

        // Arrays to count the number of elements marked in each row and column
        vector<int> rowc(m, 0);
        vector<int> colc(n, 0);

        // Iterate over the elements in the array
        for (int i = 0; i < arr.size(); i++) {
            int key = arr[i];
            auto loc = map[key];  // Retrieve the coordinates of the element

            rowc[loc.first]++;
            colc[loc.second]++;

            // Check if the current row or column is fully marked
            if (rowc[loc.first] == n || colc[loc.second] == m) {
                return i;
            }
        }

        return -1;  // Return -1 if no row or column is fully marked
    }
};