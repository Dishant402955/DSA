class Solution {
public:
bool check(vector<int>&c,int mid,long long k)
{
    for(int i=0;i<c.size();i++)
    {
        k-=(c[i]/mid);
        if(k<=0)
        {
            return true;
        }

    }
    return false;
}
    int maximumCandies(vector<int>& c, long long k) {
        int n=c.size();
        int low=1;
        int high=*max_element(c.begin(),c.end());
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(check(c,mid,k))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};