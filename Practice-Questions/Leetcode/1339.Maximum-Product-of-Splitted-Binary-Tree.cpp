class Solution {
public:
    long long total = 0, best = 0;
    static const int MOD = 1000000007;

    long long sum(TreeNode* root) {
        if (!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;
        long long s = root->val + dfs(root->left) + dfs(root->right);
        best = max(best, s * (total - s));
        return s;
    }

    int maxProduct(TreeNode* root) {
        total = sum(root);
        dfs(root);
        return best % MOD;
    }
};
