class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
          return false;
        }

        if(x==0){
          return true;
        }

        vector<int> nums;

        while(x){
          nums.push_back(x%10);
          x = x/10;
        }

        int n = nums.size();

        for(int i=0; i<n/2; i++){
          if(nums[i] != nums[n-i-1]){
            return false;
          }
        }

        return true;
    }
};