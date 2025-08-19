class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long total = 0;
        for(int& n:nums){
            if(n == 0) {
                count++;
                total+=count;
            } else{
                count = 0;
            }
        }
        return total;

    }
};
