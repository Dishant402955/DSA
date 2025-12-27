
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<long long, vector<long long>, greater<long long>> freeRooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyRooms;
        vector<int> count(n, 0);
        for (int i = 0; i < n; ++i) freeRooms.push(i);
        for (auto& m : meetings) {
            int start = m[0], end = m[1];
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }
            if (!freeRooms.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                count[room]++;
                busyRooms.push({end, room});
            } else {
                auto [availTime, room] = busyRooms.top(); busyRooms.pop();
                count[room]++;
                busyRooms.push({availTime + (end - start), room});
            }
        }
        int maxRoom = 0;
        for (int i = 1; i < n; ++i)
            if (count[i] > count[maxRoom]) maxRoom = i;
        return maxRoom;
    }
};
