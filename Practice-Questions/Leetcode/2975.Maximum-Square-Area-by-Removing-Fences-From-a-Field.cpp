class Solution {
public:
    int maximizeSquareArea(int totalHeight, int totalWidth, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const long long MOD = 1000000007;

        auto prep = [&](vector<int>& cuts, int limit) {
            sort(cuts.begin(), cuts.end());
            vector<int> fullCuts; fullCuts.push_back(1);
            for (auto &x: cuts) fullCuts.push_back(x);
            fullCuts.push_back(limit);
            return fullCuts;
        };

        vector<int> h = prep(horizontalCuts, totalHeight);
        vector<int> v = prep(verticalCuts, totalWidth);

        unordered_set<int> gapSet;
        for(int i=0;i<h.size();i++)
            for(int j=i+1;j<h.size();j++)
                gapSet.insert(h[j]-h[i]);

        long long best = 0;
        for(int i=0;i<v.size();i++)
            for(int j=i+1;j<v.size();j++) {
                int d = v[j]-v[i];
                if(d>best && gapSet.count(d)) best=d;
            }

        return best==0 ? -1 : (int)((best*best)%MOD);
    }
};
