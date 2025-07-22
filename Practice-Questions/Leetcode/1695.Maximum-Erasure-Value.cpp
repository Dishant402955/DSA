class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        int i=0;
        int j=0;
        int currsum=0;
        unordered_map<int,int>mp;
        while(j<nums.size()){
      currsum+=nums[j];
      mp[nums[j]]++;
      while(mp[nums[j]]!=1){
        mp[nums[i]]--;
        currsum-=nums[i];
        i++;

      }
      ans=max(ans,currsum);
      j++;
        }
        return ans;
    }
};
