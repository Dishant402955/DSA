#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int, int>> events;

        // Convert meetings into start (+1) and end (-1) events
        for (auto& meeting : meetings) {
            events.push_back({meeting[0], 1});
            events.push_back({meeting[1] + 1, -1});
        }

        // Sort events by day
        sort(events.begin(), events.end());

        int availableDays = 0, activeMeetings = 0, prevDay = 1;

        for (auto& event : events) {
            int currDay = event.first, change = event.second;

            if (activeMeetings == 0) {
                availableDays += (currDay - prevDay);
            }

            activeMeetings += change;
            prevDay = currDay;
        }

        // Count free days after the last meeting
        if (activeMeetings == 0) {
            availableDays += (days - prevDay + 1);
        }

        return availableDays;
    }
};