// pmr::unordered_map version 
#include <memory_resource>
pmr::unsynchronized_pool_resource pool;
pmr::unordered_map<int, int> freq(&pool);
class Solution {
public:
    static int longestBalanced(vector<int>& nums) {
        const int n=nums.size();
        freq.reserve(n);
        int len=0;
        for(int l=0; l<n; l++){
            int cnt[2]={0};
            freq.clear();
            for(int r=l; r<n; r++){
                const int x=nums[r];
                if (++freq[x]==1) cnt[x&1]++;
                if (cnt[0]==cnt[1])
                    len=max(len, r-l+1);
            }
        }
        return len;
    }
};
