class Solution {
public:
// int ans = 100000;


    int minTimeToReach(vector<vector<int> >& moveTime){
      int n = moveTime.size();
      int m = moveTime[0].size();

        // vector<vector<int> >dp(n,vector<int>(m,-1));
        // int time =0;
        // int k = solve(0,0,moveTime,dp,time);
        // return ans;


        int row[4] = {-1,0,1,0};
    int col[4] = {0,1,0,-1};
      
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
    
    pq.push(make_pair(0,make_pair(0,0)));

        int ans = INT_MAX;
        while(pq.size()>0){
            int size = pq.size();

            for(int i =0;i<size;i++){
                auto frnt = pq.top();
                pq.pop();
                int r = frnt.second.first;
                int c = frnt.second.second;
                 int wt = frnt.first;
                if(r==n-1 && c == m-1){
                    ans = min(ans,wt);
                }
               

                  for(int l=0;l<4;l++){
                          int p1 = r + row[l];
                          int p2 = c + col[l];
                    if( p1>=0 && p2 >=0 && p1<moveTime.size() && p2<moveTime[0].size() && moveTime[p1][p2] != -1 ){
                        int v= moveTime[p1][p2];
                        if(wt<v){
                            pq.push(make_pair(v+1,make_pair(p1,p2)));

                        }
                        else{
                            pq.push(make_pair(wt+1,make_pair(p1,p2)));
                        }
                        moveTime[p1][p2] = -1;

                  }



            }
        }
        

        
    }
    return ans;
    }
};