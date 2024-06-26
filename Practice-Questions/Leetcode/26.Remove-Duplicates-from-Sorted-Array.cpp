class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    
        int size = nums.size();
        
        vector<int> helper;
        helper.push_back(nums[0]); 
        
        int last = 0;
        
        for(int i = 1 ; i < size  ; i++){
            
            if( helper[last]  == nums[i] ){
                continue;
            }
            
            helper.push_back(nums[i]);
            last++;
            
        }
        
        for(int i = 0 ; i < helper.size() ; i++){
            nums[i] = helper[i] ;
        }
        
        return helper.size() ;
        
    }
};