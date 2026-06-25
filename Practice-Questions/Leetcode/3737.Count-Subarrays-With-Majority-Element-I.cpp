class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        vector<int>temp(n+1,0);
        for(int i=0;i<n;i++){
            temp[i+1] = temp[i]+(nums[i]==target);
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
            int len = j-i+1;
                int ct = temp[j+1]-temp[i];
                if(ct*2>len)ans++;
            }
        }
        return ans;
    }
};
