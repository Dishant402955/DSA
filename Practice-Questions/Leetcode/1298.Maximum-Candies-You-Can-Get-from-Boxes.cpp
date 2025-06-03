class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = candies.size();
        vector<bool> hasKey(n, false), hasBox(n, false), opened(n, false);
        queue<int> q;
        for (int box : initialBoxes) {
            hasBox[box] = true;
            q.push(box);
        }

        int totalCandies = 0;
        while (!q.empty()) {
            int box = q.front(); q.pop();

            if (!status[box] && !hasKey[box]) continue;
            if (opened[box]) continue; 

            opened[box] = true;
            totalCandies += candies[box];

            for (int key : keys[box]) {
                if (!hasKey[key]) {
                    hasKey[key] = true;
                    if (hasBox[key] && !opened[key])
                        q.push(key);
                }
            }

            for (int contained : containedBoxes[box]) {
                if (!hasBox[contained]) {
                    hasBox[contained] = true;
                    q.push(contained);
                } else if (!opened[contained]) {
                    q.push(contained); 
                }
            }
        }

        return totalCandies;
    }
};