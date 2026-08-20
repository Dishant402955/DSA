class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int l = nums[0], r = nums[1];
        nums[1] *= -1;

        for(int i = 2; i < nums.size(); i++) {
            if(l > r) {
                l = nums[i];
            } else {
                r        = nums[i];
                nums[i] *= -1;
            }
        }

        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) 
            if(nums[i] > 0) 
                ans.push_back(nums[i]);

        for(int i = 0; i < nums.size(); i++)
            if(nums[i] < 0)
                ans.push_back(-nums[i]);

        return ans;
    }
};
