class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int mini = -1;
        int maxi = -1;
        int lastSeenInvalidBound = -1;

        for(int i = 0; i<n; i++){
            // Mark the last Seen element which is out of bound
            if(nums[i] < minK || nums[i] > maxK){
                lastSeenInvalidBound = i;
            }
            // If we found minK
            else if(nums[i] == minK){
                mini = i;
            }
            // If we found maxK
            if(nums[i] == maxK){
                maxi = i;
            }

            // Now we will count the difference between starting of subarray where both maxk, mink present 
            // with last seen invalid Bound element
            ans += max(0, min(mini, maxi) - lastSeenInvalidBound);
        }
        return ans;
    }
};