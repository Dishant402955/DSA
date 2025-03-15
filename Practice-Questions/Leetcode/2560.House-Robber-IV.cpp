class Solution {
public:
    bool check(vector<int> &nums, int k, int mid){
        int houseRobbed = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] <= mid){
                houseRobbed++;
                i++;
            }
            if(houseRobbed >= k)
                return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int mid;
        while(low <= high){
            mid = (low + high)/2;
            if(check(nums, k, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};