class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        stack<int> st; //To store path from bob till 0
        int n=amount.size();
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        st.push(bob);
        auto dfs1=[&](int node,int parent,auto &&F)->void{
            if(st.top()==0) return;
            for(auto it:adj[node]){
                if(it==parent) continue;
                st.push(it);
                F(it,node,F);
                if(st.top()!=0) st.pop();
            }
        };
        dfs1(bob,-1,dfs1);// Got the path from bob till 0 in stack
        
        int len=st.size();
        map<int,int> times;
        len--;
        while(!st.empty()){
            times[st.top()]=len; //adding the time taken by bob to reach each node
            st.pop();
            len--;
        }
        auto dfs2=[&](int node,int parent,int t,auto &&F)->int{
            int cost=0;
            //This if-else calculates if Alice will get the amount or not
            if(!times.count(node)){
                cost+=amount[node];
            }else{
                if(t<times[node]) cost+=amount[node];
                else if(t==times[node]) cost+=amount[node]/2;
            }
            int res=-1e8;
            //Calculating maximum path sum
            for(auto it:adj[node]){
                if(it==parent) continue;
                res=max(res,F(it,node,t+1,F));
            }
            if(res==-1e8) res=0;
            return res+cost;
        };
        return dfs2(0,-1,0,dfs2);
    }
};