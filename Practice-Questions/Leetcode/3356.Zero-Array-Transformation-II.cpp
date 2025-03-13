class Solution {
    int n;
    int q;

    bool isvalid(vector<int>& nums, vector<vector<int>>& que, int k) {
        vector<int> dist(n, 0);

        for (int i = 0; i <= k; i++) {
            int l = que[i][0], r = que[i][1], val = que[i][2];
            dist[l] += val;
            if (r + 1 < n)
                dist[r + 1] -= val;
        }

        int cum_sum = 0;
        for (int i = 0; i < n; i++) {
            cum_sum += dist[i];
            dist[i] += cum_sum;
            if (nums[i] - cum_sum > 0) return false;  
        }
        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& que) {
        n = nums.size();
        q = que.size();

        auto lambda = [](int x) { return x == 0; };
        if (all_of(begin(nums), end(nums), lambda)) {
            return 0; // no query required because all are already zero
        }

        int l = 0;
        int h = q - 1;
        int ans = -1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (isvalid(nums, que, mid) == true) {
                ans = mid + 1;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};