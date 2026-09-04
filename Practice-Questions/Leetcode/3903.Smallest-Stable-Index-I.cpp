class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        std::vector<int> min;
        min.reserve(n);
        int max=nums[0];
        int minVal=nums[n-1];
        min.push_back(minVal);
        for(int i=n-2;i>=0;--i){
            minVal=std::min(minVal,nums[i]);
            min.push_back(minVal);
        }
        for(int i=0;i<n;++i){
            max=std::max(max,nums[i]);
            if(max-min.back()<=k)return i;
            min.pop_back();
        }
        return -1;
    }
};
