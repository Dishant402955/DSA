class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int result = 0;
        
        int count1s = 0;
        // count0s is just n - ones;

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] % 2;
            if (nums[i] == 1) {
                count1s++;
            }
        }

        result = max(count1s, n - count1s);

        int sub_start1s = 0;
        int sub_start0s = 0;
        for (int i = 0; i < n; i++) {
            if (sub_start1s % 2 == 0 && nums[i] == 1) {
                sub_start1s++;
            }

            if (sub_start1s % 2 == 1 && nums[i] == 0) {
                sub_start1s++;
            }


            if (sub_start0s % 2 == 0 && nums[i] == 0) {
                sub_start0s++;
            }

            if (sub_start0s % 2 == 1 && nums[i] == 1) {
                sub_start0s++;
            }
        }
 
        result = max(result, max(sub_start0s, sub_start1s));
        return result;

    }
};
