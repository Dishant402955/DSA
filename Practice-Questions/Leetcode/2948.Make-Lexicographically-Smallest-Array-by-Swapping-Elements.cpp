class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
       
        vector<pair<int,int>>vp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            vp.push_back({nums[i],i});
        }
        sort(vp.begin(),vp.end());
        vector<int>e;
        int l = 0;
        e.push_back(vp[0].second);
        for(int i=1;i<n;i++){
            if(vp[i].first-vp[i-1].first <= limit){
                e.push_back(vp[i].second);
            }
            else {
                sort(e.begin(),e.end());
                 int a = 0;
                for(int j=l;j<i;j++){
                    nums[e[a]] = vp[j].first;
                    a++;
                }
                e.assign(0,0);
                e.push_back(vp[i].second);
                l = i;
            }
        }
        sort(e.begin(),e.end());
                 int a = 0;
                for(int j=l;j<=n-1;j++){
                    nums[e[a]] = vp[j].first;
                    a++;
                }
                
        return nums;
    }
};
