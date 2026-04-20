//translated using AI
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;

        // Compare with first house
        for (int i = n - 1; i >= 0; i--) {
            if (colors[i] != colors[0]) {
                maxDist = i;
                break;
            }
        }

        // Compare with last house
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[n - 1]) {
                maxDist = max(maxDist, n - 1 - i);
                break;
            }
        }

        return maxDist;
    }
};
