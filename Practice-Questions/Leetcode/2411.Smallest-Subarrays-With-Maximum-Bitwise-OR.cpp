class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixOR(n);
        suffixOR[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; --i){
            suffixOR[i] = suffixOR[i + 1] | nums[i];
        }

        vector<vector<int>> prefixBitSum(n, vector<int>(30, 0));
        bitset<30> bits(nums[0]);
        for(int i = 0; i < 30; ++i){
            prefixBitSum[0][i] = bits[i];
        }
        for(int i = 1; i < n; ++i){
            bitset<30> bits(nums[i]);
            for(int j = 0; j < 30; ++j){
                prefixBitSum[i][j] = prefixBitSum[i - 1][j] + bits[j];
            }
        }

        auto isValid = [&](vector<int>& arr, int endInd) {
            if(endInd >= n) return true;
            int tmp = suffixOR[endInd];
            for(int i = 0; i < 30; ++i){
                if(arr[i] == 0 && ((tmp >> i) & 1)){
                    return false;
                }
            }
            return true;
        };

        vector<int> res;
        for(int i = 0; i < n; ++i){
            int lo = 0;
            int hi = n - i - 1;  // 修正：避免 out-of-bounds
            int ans = 0;

            while(lo <= hi){
                int len = lo + (hi - lo) / 2;
                vector<int> arr = prefixBitSum[i + len];
                if(i > 0){
                    for(int j = 0; j < 30; ++j){
                        arr[j] -= prefixBitSum[i - 1][j];
                    }
                }
                if(isValid(arr, i + len)){  // 修正：endInd 為 i + len - 1 → i + len
                    ans = len;
                    hi = len - 1;
                } else{
                    lo = len + 1;
                }
            }

            res.push_back(ans + 1);
        }

        return res;
    }
};
