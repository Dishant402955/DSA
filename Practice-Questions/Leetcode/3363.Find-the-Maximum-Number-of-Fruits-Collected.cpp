#define ll long long
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& a) {
        ll n = a.size();
        int ans = 0;
        for (ll x = 0; x < n; x++) {
            ans += a[x][x];
            a[x][x] = 0;
        }
        /*for (ll i = 0; i < (ll)(n / 2); i++) {
            for (ll j = i + 1; j < n - i - 1; j++) {
                a[i][j] = 0;
                a[j][i] = 0;
            }
        }*/
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
        dp[0][n - 1] = a[0][n - 1]; dp[n - 1][0] = a[n - 1][0];
        for (ll i = 1; i < n - 1; i++) {
            for (ll j = n - 1; j >= (i >= n / 2 ? n - (n - i - 1) : n - i - 1); j--) {
                //cout << j << " " << i << endl;
                dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]}) + a[i][j];
                dp[j][i] = max({dp[j - 1][i - 1], dp[j][i - 1], dp[j + 1][i - 1]}) + a[j][i];
                
            }
        }
        /*for (vector<ll> b : dp) {
            for (ll x : b) {
                cout << x << " ";
            }
            cout << endl;
        }*/
        ans += dp[n - 2][n - 1] + dp[n - 1][n - 2];
        return ans;
    }
};
