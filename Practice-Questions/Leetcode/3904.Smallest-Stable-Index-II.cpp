class Solution {
public:
    static int firstStableIndex(vector<int>& nums, int k) {
        const int n=nums.size();
        static int suf[100000];
        int xMin=nums.back();
        for (int i=n-1; i>=0; i--){
            xMin=min(nums[i], xMin);
            suf[i]=xMin;
        }
        int xMax=-1;
        for (int i=0; i<n; i++){
            xMax=max(xMax, nums[i]);
            if (xMax-suf[i]<=k) return i;
        }
        return -1;
    }
};
