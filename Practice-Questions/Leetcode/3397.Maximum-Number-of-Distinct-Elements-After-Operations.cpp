class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        int cnt=0, prev=INT_MAX;
        for(int i=nums.size()-1; i>=0; i--){
            pop_heap(nums.begin(), nums.begin()+i+1);
            int x=nums[i]; 
            int xm=x-k, xx=x+k;
            if (prev>xx){
                prev=xx;
                cnt++;
            }
            else if (prev>xm){
                prev--;
                cnt++;
            }
        }
        return cnt;
    }
};
