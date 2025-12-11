class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();
        unordered_map<int, vector<int>> rowCols;
        unordered_map<int, vector<int>> colRows;
        rowCols.reserve(m*2);
        colRows.reserve(m*2);
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            rowCols[x].push_back(y);
            colRows[y].push_back(x);
        }
        for (auto &p : rowCols) {
            auto &vec = p.second;
            sort(vec.begin(), vec.end());
        }
        for (auto &p : colRows) {
            auto &vec = p.second;
            sort(vec.begin(), vec.end());
        }

        int covered = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            auto &rvec = rowCols[x];
            auto itR = lower_bound(rvec.begin(), rvec.end(), y);
            bool hasLeft = (itR != rvec.begin());      
            bool hasRight = (itR != rvec.end() && *itR == y && (itR + 1) != rvec.end()); 
            auto &cvec = colRows[y];
            auto itC = lower_bound(cvec.begin(), cvec.end(), x);
            bool hasAbove = (itC != cvec.begin());
            bool hasBelow = (itC != cvec.end() && *itC == x && (itC + 1) != cvec.end());

            if (hasLeft && hasRight && hasAbove && hasBelow) ++covered;
        }

        return covered;
    }
};
