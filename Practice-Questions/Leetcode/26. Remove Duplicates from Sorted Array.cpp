class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    
        set<int> num;

        for(int i: nums){
          num.insert(i);
        }

        int count = 0;

        for(int i: num){
          nums[count++] = i;
        }

        return num.size();
        
    }
};