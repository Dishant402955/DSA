class Solution {
private:
    bool travelBFS(int src, vector<bool>& vis, vector<vector<int>>& adj){
        int nodes = 0;
        int edges = 0;

        queue<int> q;
        q.push(src);
        vis[src] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            nodes++;

            for(auto adjN:adj[node]){
                edges++;
                if(!vis[adjN]){
                    q.push(adjN);
                    vis[adjN] = 1;
                }
            }
        }

        return nodes*(nodes-1)==edges;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,0);
        vector<vector<int>> adj(n);

        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int cnt = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(travelBFS(i,vis,adj)){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};