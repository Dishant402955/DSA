class Solution {
public:
    vector<int> seg;
    
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        seg.resize(4 * n);
        build(baskets, 0, 0, n - 1);
        
        int unplaced = 0;
        for (int fruit : fruits) {
            if (seg[0] < fruit) {
                unplaced++;
            } else {
                if (!place(0, 0, n - 1, fruit)) {
                    unplaced++;
                }
            }
        }
        return unplaced;
    }

    void build(vector<int>& b, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = b[l];
            return;
        }
        int mid = (l + r) / 2;
        build(b, 2 * idx + 1, l, mid);
        build(b, 2 * idx + 2, mid + 1, r);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    bool place(int idx, int l, int r, int val) {
        if (seg[idx] < val) return false;
        if (l == r) {
            seg[idx] = -1;
            return true;
        }
        int mid = (l + r) / 2;
        bool placed = place(2 * idx + 1, l, mid, val);
        if (!placed)
            placed = place(2 * idx + 2, mid + 1, r, val);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
        return placed;
    }
};
