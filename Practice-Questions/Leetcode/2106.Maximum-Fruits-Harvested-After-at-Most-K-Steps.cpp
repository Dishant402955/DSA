class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int minPos = startPos - k;
        int maxPos = startPos + k;

        for (auto& f : fruits) {
            minPos = min(minPos, f[0]);
            maxPos = max(maxPos, f[0]);
        }

        int offset = -minPos + 1;
        int size = maxPos - minPos + 3;

        vector<int> fruitsAt(size, 0);
        for (auto& f : fruits) {
            fruitsAt[f[0] + offset] = f[1];
        }

        vector<int> pfx(size, 0);
        for (int i = 1; i < size; ++i) {
            pfx[i] = pfx[i - 1] + fruitsAt[i];
        }

        auto getSum = [&](int l, int r) -> int {
            l = max(l, minPos); r = min(r, maxPos);
            l += offset;
            r += offset;
            r = min(r, size - 1); 
            return pfx[r] - (l > 0 ? pfx[l - 1] : 0);
        };

        int ans = 0;

        for (int stepsLeft = 0; stepsLeft <= k; ++stepsLeft) {
            int left = startPos - stepsLeft;
            int remaining = k - 2 * stepsLeft;
            if (remaining < 0) continue;
            int right = startPos + remaining;
            ans = max(ans, getSum(left, right));
        }

        for (int stepsRight = 0; stepsRight <= k; ++stepsRight) {
            int right = startPos + stepsRight;
            int remaining = k - 2 * stepsRight;
            if (remaining < 0) continue;
            int left = startPos - remaining;
            ans = max(ans, getSum(left, right));
        }

        return ans;
    }
};
