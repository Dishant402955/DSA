template <class T, T default_value = T(), auto merge_node = plus<>()>
struct SegmentTree {
    int n;
    vector<T> tree;

    SegmentTree(int size) {
        n = 1;
        while(n < size) n *= 2;
        tree.resize(2*n, default_value);
    }

    void update(int pos, T val) {
        tree[n + pos] = val;
        for(int idx = (n + pos) >> 1; idx > 0; idx >>= 1) {
            tree[idx] = merge_node(tree[idx<<1], tree[idx<<1|1]);
        }
    }

    T query(int l, int r) {
        T resLeft = default_value, resRight = default_value;
        for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) resLeft = merge_node(resLeft, tree[l++]);
            if(r & 1) resRight = merge_node(tree[--r], resRight);
        }
        return merge_node(resLeft, resRight);
    }
};

class Solution {
public:
    int maximumJumps(vector<int>& nums, long long target) {
        int n = nums.size();
        set<long long> st;
        for(int x : nums)
            st.insert(x), st.insert(x - target), st.insert(x + target);

        map<long long, int> mapping;
        int m = 0;
        for(long long val : st) mapping[val] = m++;

        SegmentTree<int, -1, [](int a, int b) { return max(a, b); }> segtree(m);
        vector<int> dp(n, -1);
        for(int i = n - 1; i >= 0; i--) {
            int mx = segtree.query(mapping[nums[i] - target], mapping[nums[i] + target]);

            if(i == n - 1) dp[i] = 0;
            else dp[i] = (mx == -1) ? -1 : (mx + 1);
            segtree.update(mapping[nums[i]], dp[i]);
        }
        return dp[0];
    }
};
