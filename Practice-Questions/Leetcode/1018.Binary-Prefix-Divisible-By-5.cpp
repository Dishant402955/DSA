
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int msb=0, n=nums.size();
        vector<bool> ans(n);
        for(int i=0; i<n; i++){
            msb=((msb<<1)+nums[i]);// msb<=9
            msb-=(-(msb>=5) & 5); // if msb>=5 msb-=5
            ans[i]=msb==0;
        }
        return ans;
    }
};
