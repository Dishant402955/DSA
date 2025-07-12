class Solution {
public:
    int minRound = INT_MAX, maxRound = INT_MIN;
    bool visited[30][30][30] = {};

    void dfs(int mask, int round, int i, int j, int first, int second, int l, int m, int r) {
        if (i >= j) {
            dfs(mask, round + 1, 0, 27, first, second, l, m, r);
        } else if ((mask & (1 << i)) == 0) {
            dfs(mask, round, i + 1, j, first, second, l, m, r);
        } else if ((mask & (1 << j)) == 0) {
            dfs(mask, round, i, j - 1, first, second, l, m, r);
        } else if (i == first && j == second) {
            minRound = min(minRound, round);
            maxRound = max(maxRound, round);
        } else if (!visited[l][m][r]) {
            visited[l][m][r] = true;
            // simulate player i losing
            if (i != first && i != second)
                dfs(mask ^ (1 << i), round, i + 1, j - 1, first, second, l - (i < first), m - (i > first && i < second), r - (i > second));
            // simulate player j losing
            if (j != first && j != second)
                dfs(mask ^ (1 << j), round, i + 1, j - 1, first, second, l - (j < first), m - (j > first && j < second), r - (j > second));
        }
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        dfs((1 << n) - 1, 1, 0, 27, firstPlayer - 1, secondPlayer - 1, firstPlayer - 1, secondPlayer - firstPlayer - 1, n - secondPlayer);
        return {minRound, maxRound};
    }
};
