class Solution {
public:
    bool uniformArray(vector<int>& nums) {

        int a = *min_element(nums.begin(), nums.end());

        if(a % 2 == 1) return true;  // min is odd, can make everything odd

        for(int i : nums)
            if(i % 2 == 1) return false; // min is even but odd exists, impossible

        return true; // all even already
    }
};
