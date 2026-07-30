class Solution {
public:
    int minimumPushes(string word) 
    {
        int n = word.size();
        int ans = 0;
        while(n>0)
        {
            ans+=n; 
            n=n-8;
        }
        return ans;
    }
//please upvote...
};
