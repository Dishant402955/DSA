class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), ans = startTime[0], curr = startTime[0], leftInd = 0, gapCnt = 1;
        
        for(int i = 1; i <= n; i++) {
            curr += (i == n) ? eventTime - endTime[n-1] : startTime[i] - endTime[i-1];
          
            if(++gapCnt > k + 1) {
                curr -= (leftInd == 0) ? startTime[0] : startTime[leftInd] - endTime[leftInd - 1];
                gapCnt--, leftInd++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};
