int minimumOperations(vector<int>& nums) {
      int count = 0;

      while(!isDistinct(nums)){
          int temp = 0;
          if(nums.size() >= 3)  temp = 3;
          else  temp = nums.size();

          for(int i=0; i<temp; i++){
            nums.erase(nums.begin());
          }

          count++;
      }
      
      return count;
    }

    bool isDistinct(vector<int>& nums){
      if(nums.size() == 0)  return true;
      
      unordered_map<int,int> m;
      for(int i : nums){
        m[i] = 0;
      }
      return nums.size() == m.size();
    }