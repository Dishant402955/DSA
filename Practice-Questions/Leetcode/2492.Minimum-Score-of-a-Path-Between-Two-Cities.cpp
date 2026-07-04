constexpr int N=1e5+1;
struct Edge{int v, w, nxt=-1;};
Edge E[N*2];// undirected
int eIdx=0;
int adj[N];
inline void addEdge(int u, int v, int w){
    E[eIdx]={v, w, adj[u]};
    adj[u]=eIdx++;
}
bitset<N> vis;
class Solution {
public:
    static void dfs(int i,  int& dist) {
        vis[i]=1;
        for (int idx=adj[i]; idx!=-1; idx=E[idx].nxt) {
            const int v=E[idx].v, w=E[idx].w;
            dist= min(dist, w);
            if (!vis[v]) 
                dfs(v, dist);
        }
    }
    static void adjacent_ini(int n, vector<vector<int>>& roads){
        eIdx=0;
        memset(adj+1, -1, sizeof(int)*n);
        for (auto& path : roads) {
            const int u=path[0] , v=path[1], w=path[2];
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
    }

    static int minScore(int n, vector<vector<int>>& roads)
    {      
        adjacent_ini(n, roads);
        vis.reset();
        int dist=INT_MAX;
        dfs(1, dist);

        return dist;
    }
};
