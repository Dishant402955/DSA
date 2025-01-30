class Solution {
public:
    bool check(int node, vector<int>& col, vector<vector<int>>& adj) {
        col[node] = 0;
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            for (auto neighbor : adj[front]) {
                if (col[neighbor] == -1) {
                    col[neighbor] = !col[front];
                    q.push(neighbor);
                } else if (col[neighbor] == col[front]) {
                    return false;
                }
            }
        }
        return true;
    }

    int bfs_max_depth(int start, vector<vector<int>>& adj) {
        vector<bool> vis(adj.size(), false);
        queue<int> q;
        q.push(start);
        vis[start] = true;
        int depth = 0;

        while (!q.empty()) {
            int sz = q.size();
            depth++;
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                for (int neighbor : adj[node]) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
        return depth;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1); // Create a Adjacency list //O(V*E)
        for (auto& edge : edges) { // Since it is an undirected edge conside
                                   // every edge to be bidirectional
            // O(Edges)
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> col(n + 1, -1); // To track  the color of each node
        for (int i = 1; i <= n; i++) {
            if (col[i] == -1 &&
                !check(i, col, adj)) { // Check BiPartite Condition
                return -1;
            }
        }

        vector<bool> visited(n + 1, false);
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {

                queue<int> q;
                vector<int> component; // To keep a track of all components
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);
                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                int max_depth = 0;
                for (int node : component) { // Find the max depth of in all
                                             // component and then just add it
                    max_depth = max(max_depth, bfs_max_depth(node, adj));
                }
                ans += max_depth;
            }
        }
        return ans;
        //Time Complexity :O(V+E)
        //Space Complexity :O(V+E)
    }
};