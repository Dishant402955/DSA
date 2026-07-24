class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        
        // Step 1: Store all unique XOR pairs
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                s.insert(nums[i] ^ nums[j]);
            }
        }
        
        unordered_set<int> ans;
        
        // Step 2: XOR the unique pairs with the third element
        for(auto it : s){
            for(int i = 0; i < n; i++){
                ans.insert(it ^ nums[i]);
            }
        }
        
        return ans.size();
    }
};
