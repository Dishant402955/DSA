#define ll long long

struct DSU{
    vector<ll>par, sz;
    ll sm, components;

    DSU(ll n){
        sm = 0, components = n;
        par = sz = vector<ll>(n + 1);
        for(int i = 0 ; i <= n ; i++)par[i] = i , sz[i] = 1;
    }

    ll findlead(ll n){
        if(par[n] == n)return n;
        return par[n] = findlead(par[n]);
    }

    bool merge(ll x, ll y, ll c){
        x = findlead(x), y = findlead(y);
        if(x == y)return 0;

        sm += c, components--;
        if(sz[x] >= sz[y])sz[x] += sz[y], par[y] = x;
        else sz[y] += sz[x], par[x] = y;
        return 1;
}
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU op(n);

        vector<int>ans;
        for(auto i : edges)
            if(!op.merge(i[0], i[1] ,0))
                ans = {i[0], i[1]};

        return ans;
    }
};