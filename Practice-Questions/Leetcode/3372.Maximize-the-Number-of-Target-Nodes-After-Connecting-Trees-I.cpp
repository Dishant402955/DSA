class Solution {
public:
    void findnodes(vector<vector<int>> adj,vector<vector<int>> &dp,int n ,vector<int> &high){
        int itr=0;
        for(int i=0;i<n;i++){
            vector<int> visited(n,0);
            queue<int> q;
            itr = 0;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int t=q.size();
                if(itr==0)
                    dp[i][itr]=t;
                else
                    dp[i][itr]=dp[i][itr-1]+t;
                for(int j=0;j<t;j++){
                    int x=q.front();
                    q.pop();
                    for(auto y:adj[x]){
                        if(!visited[y]){
                            visited[y]=1;
                            q.push(y);
                        }
                    }
                }
                itr++;
            }
            high.push_back(itr-1);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        cout<<n<<" "<<m;
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);
        vector<vector<int>> dp1(max(n,k)+1,vector<int>(max(n,k)+1,0));
        vector<vector<int>> dp2(max(m,k)+1,vector<int>(max(m,k)+1,0));
        vector<int> depth(n,0) , depth2(m,0);
        for(auto x:edges1){
            adj1[x[0]].push_back(x[1]);
            adj1[x[1]].push_back(x[0]);
        }
        for(auto x:edges2){
            adj2[x[0]].push_back(x[1]);
            adj2[x[1]].push_back(x[0]);
        }
        vector<int> high,high2;
        findnodes(adj1,dp1,n ,high);
        findnodes(adj2,dp2,m,high2);
        vector<int> answer;
        for(int i=0;i<n;i++){
            int temp = 0;
            if(k-1 >= 0)
           for(int j=0; j<m; j++){
               temp = max(temp , dp2[j][min(high2[j] , k-1)]);
           }
           answer.push_back(dp1[i][min(high[i],k)] + temp);
        }
        return answer;
    }

       
    
};