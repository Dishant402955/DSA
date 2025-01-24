class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for(int u = 0; u < n; ++u) {
            for(int v : graph[u]) {
                adj[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;
        for(int u = 0; u < n; ++u)
            if(!indegree[u])
                q.push(u);
        
        vector<int> ans;
        while(!q.empty()) {

            int u = q.front(); q.pop();
            ans.push_back(u);
            
            for(int v : adj[u]) {
                indegree[v]--;

                if(!indegree[v])
                    q.push(v);
            }
        }

        sort(begin(ans), end(ans));
        return ans;
    }
};