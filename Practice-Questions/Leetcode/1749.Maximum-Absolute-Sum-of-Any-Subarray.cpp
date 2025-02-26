/*
By   :: savetrees
Used :: Kadane Algo
*/
class Solution {
public:
    int kadane_1(vector<int>&nums)
    {
        int maxi_sum=nums[0];
        int cur_sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            cur_sum=max(cur_sum+nums[i],nums[i]);
            maxi_sum=max(maxi_sum,cur_sum);
        }
        return maxi_sum;
    }
    int kadane_2(vector<int>&nums)
    {
        int mini_sum=nums[0];
        int cur_sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            cur_sum=min(cur_sum+nums[i],nums[i]);
            mini_sum=min(mini_sum,cur_sum);
        }
        return mini_sum;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=kadane_1(nums);
        int mini=kadane_2(nums);
        return max(maxi,abs(mini));
    }
};