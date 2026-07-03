class Solution {
public:
    typedef long long ll;
    typedef pair<long long,int> p;
    
    bool check(vector<vector<pair<int,int>>>& graph,vector<bool>& online,ll mid,ll k){
        int n=graph.size();
        vector<ll> cost(n, LLONG_MAX);
        cost[0]=0;
        
        priority_queue< p , vector<p> , greater<p> > pq;
        pq.push({0,0});

        while(!pq.empty()){
            ll cst=pq.top().first , node=pq.top().second;
            pq.pop();

            if(cst > cost[node]) continue;
            if(online[node]==false) continue;

            for(auto x : graph[node]){
                int adjnode=x.first , wt=x.second;

                if(wt<mid) continue;
                if(online[adjnode]==false) continue;

                ll new_cost=cst+wt;
                if(new_cost>k) continue;

                if(new_cost<cost[adjnode]){
                    pq.push({new_cost , adjnode});
                    cost[adjnode]=new_cost;
                }
            }
        }

        return cost.back()<=k;
    }
    
    int findMaxPathScore(vector<vector<int>>& edges,vector<bool>& online,ll k){
        int n=online.size();
        int low=0 , high=-1 , ans=-1;
        
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            high=max(high,edges[i][2]);
        }

        while(low<=high){
            ll mid=(low+high)/2;

            if(check(graph,online,mid,k)){
                ans=mid;
                low=mid+1;
            }

            else high=mid-1;
        }

        return ans;
    }
};
