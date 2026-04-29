class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<long long> dpW(n+1), dpWo(n+1), ndpW(n+1), ndpWo(n+1), cSum(n+1), ncSum(n+1);

        for (int i=0;i<n;i++){
            cSum[i+1] = cSum[i] + grid[i][0];
        }

        long long dpWm = 0, ndpWm;

        for (int j=1;j<n;j++){
            ndpWm = 0;

            for (int i=0;i<n;i++){
                ncSum[i+1] = ncSum[i] + grid[i][j];
            }

            for (int i=0;i<=n;i++){
                long long woA = dpWm, wA = 0;

                for (int k=0;k<=i;k++){
                    long long x = dpWo[k] + cSum[i] - cSum[k];
                    wA = max(wA, x);
                    woA = max(woA, x);
                }

                for (int k=i+1;k<=n;k++){
                    wA = max(wA, dpW[k] + ncSum[k] - ncSum[i]);
                }
                ndpW[i] = wA;
                ndpWo[i] = woA;
                if (ndpWm < wA) ndpWm = wA;                
            } 
            swap(dpW, ndpW);
            swap(dpWo, ndpWo);
            swap(ncSum, cSum);
            dpWm = ndpWm;
        }
        return *max_element(dpW.begin(), dpW.end());
    }
};
