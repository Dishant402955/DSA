class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int r = 0, ans = 0, cur = 1;
        while (r < n || (!pq.empty())) {
            while (r < n && events[r][0] <= cur) pq.push(events[r++][1]);
            while (!pq.empty() && pq.top() < cur) pq.pop();
            if (!pq.empty()) {
                int idx = pq.top();
                pq.pop();
                ans += 1;
                cur += 1;
            }
            if (r < n && pq.empty()) cur = events[r][0];
        }
        return ans;
    }
};
