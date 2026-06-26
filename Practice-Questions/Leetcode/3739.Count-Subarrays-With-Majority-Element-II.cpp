#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll = long long;

typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        ordered_multiset pbds;
        ll cnt = 0;
        int cs = 0;
        pbds.insert({0, -1});
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) cs++;
            else cs--;
            cnt += pbds.order_of_key({cs, -2});
            pbds.insert({cs, i});
        }
        return cnt;
    }
};
