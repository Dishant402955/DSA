class Solution {
public:
    bool check(const vector<int>& nums1, const vector<int>& nums2, long long mid, long long k) {
    long long count = 0;
    for (int i : nums1) {
        if(i == 0){
            if(mid >= 0) {count += nums2.size();}
        }else if(i > 0){
            int ans = -1;
            int l = 0, r = nums2.size()-1;
            while(l <= r){
                int pos = (r+l)/2;
                if(1ll*i*nums2[pos] <= mid){
                    ans = pos;
                    l = pos+1;
                }else{
                    r = pos-1;
                }
            }
            count += (ans + 1);
        }else {
            int ans = nums2.size();
            int l = 0, r = nums2.size()-1;
            while(l <= r){
                int pos = (r+l)/2;
                if(1ll*i*nums2[pos] <= mid){
                    ans = pos;
                    r = pos-1;
                }else{
                    l = pos + 1;
                }
            }
            count += (nums2.size() - ans);
        }
    }
    return count >= k;
}
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l = -1e10;
        long long r = 1e10;
        long long ans = 0;
        while(l <= r){
            long long mid = l + (r-l)/2;
            if(check(nums1,nums2,mid,k)){
                ans = mid;
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        return ans;
    }
};
