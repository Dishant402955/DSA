class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

      vector<int> ans = {-1, -1};
      int n = nums.size();

        for(int i=0; i<n; i++){
          for(int j=i+1; j<n; j++){
            if(nums[i] + nums[j] == target){
              ans[0] = i;
              ans[1] = j;

              return ans;
            }
          }
        }


      return ans;

    }
};