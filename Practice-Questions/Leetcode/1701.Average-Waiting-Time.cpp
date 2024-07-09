class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int n = customers.size();

        double time_waiting = customers[0][1];

        int finished_prev = customers[0][0] + customers[0][1];

        for (int i = 1 ; i< n ; ++i){

            int start_cook = max(customers[i][0], finished_prev);
            int end_time = start_cook + customers[i][1];
            finished_prev = end_time;
            time_waiting += end_time - customers[i][0];
            
        }

        return time_waiting / n;
    }
};