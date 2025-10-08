class Solution {
public:

    int bs(vector<int>& potions,int start,int end,long long target){
        int mid=start+(end-start)/2;
        if(start>end)return potions.size()-start;
        else if(potions[mid]>=target)return bs(potions,start,mid-1,target);
        else return bs(potions,mid+1,end,target);
        return 0;
    }


    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans(spells.size(),0);
        sort(potions.begin(),potions.end());
        
        for(int i=0;i<spells.size();i++){
            long long val=ceil(static_cast<double>(success)/spells[i]);
            ans[i]=bs(potions,0,potions.size()-1,val);
        }
        return ans;
    }
};
