class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        int minDiff1 = INT_MAX;
        int minDiff2 = INT_MAX;
        int incrCount = 0;
        long long Sum = 0;
        for(int i = 0; i < n; i++){
            int x = nums[i] ^ k;
            if(x < nums[i]){
                minDiff1 = min(minDiff1, nums[i] - x);
                Sum += nums[i];
            }else{
                minDiff2 = min(minDiff2, x - nums[i]);
                incrCount++;
                Sum += x;
            }
        }

        if(incrCount%2 == 0){
            return Sum;
        }else{
            if(minDiff2 > minDiff1){
                // option1: keep the node1 and apply xor on node2.
                // After applying xor on node2, node2 value will decrease, so subtract that decrement
                return Sum - minDiff1;
            }else{
                // option2: Don't apply the xor on node1.
                // So we need to subtract the previous increment in node1
                return Sum - minDiff2;
            }
        }
    }
};