class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        //sliding window
        long long curr = 0ll;
        int n = prices.size();
        vector<long long> pref;
        long long sum = 0ll;
        for(int i = 0;i < n;i++){
            curr = curr + 1ll*(prices[i]*strategy[i]);
            sum = sum + prices[i];
            pref.push_back(sum);
        }

        long long ans = curr;
        int l = 0, r = k-1;
        sum = 0ll;
        for(int i=0;i<r;i++){
            sum += 1ll*(prices[i]*strategy[i]);
        }

        while(r < n){
            //maxans = max(curr - sum + change, maxans)
            //change = pref[r] - pref[mid+1]
            sum += 1ll*(prices[r]*strategy[r]);
            int mid = l + (r - l)/2;
            long long change = pref[r] - pref[mid];
            ans = max(ans, curr - sum + change);
            sum -= 1ll*(prices[l]*strategy[l]);
            l++;
            r++;
        }

        return ans;

    }
};
