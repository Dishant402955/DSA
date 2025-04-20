class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int it:answers)
        mp[it]++;
        int ans=0;
        for(auto &it:mp)
        {
            ans+=((it.second+it.first)/(it.first+1))*(it.first+1);
        }
        return ans; 
    }
};