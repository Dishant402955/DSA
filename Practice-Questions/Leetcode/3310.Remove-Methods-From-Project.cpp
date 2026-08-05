class Solution {
public:
    void dfs(int node, unordered_map<int,unordered_set<int>> &adj, unordered_set<int> &bugs, vector<int> &vis){
        bugs.insert(node);
        vis[node] = 1;

        for(auto &it : adj[node]){
            if(!vis[it]) dfs(it,adj,bugs,vis);
        }
        return;
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,unordered_set<int>> adj;

        for(auto &it : invocations){
            adj[it[0]].insert(it[1]);
        }

        unordered_set<int> bugs;
        vector<int> vis(n);
        dfs(k,adj,bugs,vis);

        bool flag = false;

        for(auto &it : adj){
            for(auto &ngb : it.second){
                if(bugs.count(ngb) && !bugs.count(it.first)){
                    flag = true;
                    break;
                }
            }
        }
        vector<int> result;
        if(flag){ // being invoked by outside group
            for(int i=0;i<n;i++){
                result.push_back(i);
            }
            return result;
        }
        for(int i=0;i<n;i++){
            if(!bugs.count(i)) result.push_back(i);
        }
        return result;
    }
};
