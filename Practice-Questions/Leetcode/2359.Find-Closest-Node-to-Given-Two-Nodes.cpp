class Solution {
public:
    
    void bfs(vector<vector<int>> &graph,int node,vector<int> &dist){
        queue<int> q;
        q.push(node);
        int step=0;
        vector<bool> vis(graph.size());
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int front=q.front();
                q.pop();
                dist[front]=step;
                vis[front]=true;
                for(int x:graph[front]){
                    if(!vis[x])q.push(x);
                }
            }
            step++;
        }
        
    }
    
    int closestMeetingNode(vector<int>& v, int node1, int node2) {
        int n=v.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(v[i]==-1)continue;
            graph[i].push_back(v[i]);
        }
        vector<int> dist1(n,1e9),dist2(n,1e9);
        bfs(graph,node1,dist1);
        bfs(graph,node2,dist2);
        int dist=1e9,ans=-1;
        for(int i=0;i<n;i++){
            if(max(dist1[i],dist2[i])<dist){
                dist=max(dist1[i],dist2[i]);
                ans=i;
            }
        }
        return ans;
        
    }
};