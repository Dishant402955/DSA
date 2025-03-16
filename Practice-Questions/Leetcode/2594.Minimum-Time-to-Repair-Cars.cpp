class Solution {
public: 
    bool can(long long t, vector<int>& ranks, int cars) {
        long long cnt = 0;
        for (int r : ranks) {
            cnt += sqrt(t / r);// t=r*c*c c=sqrt(t/r);
            if (cnt >= cars) return true;
        }
        return cnt >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1LL*(*min_element(ranks.begin(), ranks.end())) * cars * cars;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            if (can(m, ranks, cars)) r = m-1;
            else l = m + 1;
        }
        return l;
    }
};