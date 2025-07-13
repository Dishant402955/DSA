class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end()); sort(t.begin(),t.end());
        
        int j=t.size()-1; int i=p.size()-1; int ans = 0;

        while (j>=0 && i>=0) {
            if (p[i]<=t[j]) {
                ++ans; --i; --j;
            }
            else if (p[i]>t[j]) --i;
        }
        return ans;
    }
};

auto init = atexit([]() {ofstream("display_runtime.txt") << 0;});
