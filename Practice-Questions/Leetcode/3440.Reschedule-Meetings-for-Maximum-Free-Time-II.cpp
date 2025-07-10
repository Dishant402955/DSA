class Solution {
public:
    int maxFreeTime(int t, vector<int>& s, vector<int>& e) {

        int n = s.size();
        int maxm = 0;
        int maxm2 = 0;

        // Checking for gaps from both the sides
        for (int i = 0; i < n; i++) {
            // Check whether before this event we can have any gap greater than
            // this size
            if ((e[i] - s[i]) <= maxm2) {

                maxm = max(maxm, (i + 1 < n ? s[i + 1] : t) -
                                     (i - 1 >= 0 ? e[i - 1] : 0));
            }
            // Updating maxm for two consecutive gaps as we have k=1 but cannot
            // fit in any gap before
            maxm = max(maxm, (i + 1 < n ? s[i + 1] : t) -
                                 (i - 1 >= 0 ? e[i - 1] : 0) - (e[i] - s[i]));
            if (i - 1 < 0)
                maxm2 = max(maxm2, s[i]);
            else
                maxm2 = max(maxm2, s[i] - e[i - 1]);
        }

        maxm2 = 0;

        for (int i = n - 1; i >= 0; i--) {
            if ((e[i] - s[i]) <= maxm2) {

                maxm = max(maxm, (i + 1 < n ? s[i + 1] : t) -
                                     (i - 1 >= 0 ? e[i - 1] : 0));
            }
            maxm = max(maxm, (i + 1 < n ? s[i + 1] : t) -
                                 (i - 1 >= 0 ? e[i - 1] : 0) - (e[i] - s[i]));
            if (i + 1 >= n)
                maxm2 = max(maxm2, t - e[i]);
            else
                maxm2 = max(maxm2, s[i + 1] - e[i]);
        }

        return maxm;
    }
};
