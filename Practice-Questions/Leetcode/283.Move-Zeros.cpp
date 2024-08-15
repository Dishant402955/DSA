class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0 ;
        int index = 0 ;

        for (int i = 0; i < nums.size(); i++){

          if(nums[i] == 0)
            cnt++;
          else{
            nums[index++] = nums[i];
          }

        }
        
        for(int i = nums.size()-1; i >= index; i-- ){
            nums[i] = 0;
        }

    }
};