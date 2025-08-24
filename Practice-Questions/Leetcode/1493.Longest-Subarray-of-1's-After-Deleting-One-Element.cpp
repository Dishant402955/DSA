class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        vector<vector<int>> split;
        int prev=-1;
        for(int n:nums)
        {
            if(n==prev)
                split.back().push_back(n);
            else
                split.push_back({n});
            prev = n;
        }
        int ans=0;
        if(split.size()==1)
            return split[0][0] ? nums.size()-1 : 0; //all 1's or all 0's
        if(split.size()==2) //one 1's and one 0's
        {
            if(split[0][0]==1)
                return split[0].size();
            else
                return split[1].size();
        }
        for(int i=0;i<split.size()-2;i++)
        {
            if(split[i][0]==1)
            {
                if(split[i+1].size()==1)
                    ans = max(ans,(int)split[i].size()+(int)split[i+2].size());
                else
                    ans = max(ans,max((int)split[i].size(),(int)split[i+2].size()));
            }
            if(split[i+1][0]) //edge case in form 0's 1's 0's
                ans = max(ans,(int)split[i+1].size());
        }
        return ans;
    }
};
