using ll = long long;
const int mod = 1e9 +7;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {


        unordered_map<ll,ll> mp; // for [y,cnt]
        ll total =0;
        for(auto v:points){
            ll x= v[0],y=v[1];
            mp[y]++;
            total += (mp[y]-1); // haha count on the fly 
            total %=mod;
        }

        ll total_ways = total*(total-1)/2%mod; 
        

        for(auto &[y,c]:mp){
            ll curr_line = c*(c-1)/2; // c pts. cC2 lines
            ll cnt_of_same_line = curr_line*(curr_line-1)/2;
            total_ways = (total_ways - cnt_of_same_line )%mod; 
            if(total_ways < 0) total_ways+=mod; // to prevent it from going -ve  
        }
        return total_ways;
    }
};
