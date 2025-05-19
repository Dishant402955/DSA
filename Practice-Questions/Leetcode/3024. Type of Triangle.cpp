class Solution {
public:
    string triangleType(vector<int>& nums) {

        if(nums[0] == nums[1] && nums[1] == nums[2]){
          return "equilateral";
        }

        if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]){

          if(nums[0] == nums[1] && nums[0] + nums[1] > nums[2]){
            return "isosceles";
          }
          else if(nums[1] == nums[2] && nums[1] + nums[2] > nums[0]){
            return "isosceles";
          }
          else if(nums[0] == nums[2] && nums[0] + nums[2] > nums[1]){
            return "isosceles";
          }else{
            return "none";
          }

        }

        if(nums[0] + nums[1] > nums[2] && nums[2] + nums[1] > nums[0] && nums[0] + nums[2] > nums[1]) {
          return "scalene";
        }

        return "none";
    }
};