class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // Need to use binary search due to constrain 
        int n=nums.size();
        int ans=-1;
        int s=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>s){
            ans=max(ans,nums[i]-s);
            }
            else s=nums[i];
        }
        return ans;
    }
};
