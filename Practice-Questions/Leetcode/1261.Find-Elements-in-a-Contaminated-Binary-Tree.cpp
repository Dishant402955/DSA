/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class FindElements {
private:
    std::unordered_set<int> recoveredValues;

    void recoverTree(TreeNode* node, int value) {
        if (node == nullptr) {
            return;
        }
        node->val = value;
        recoveredValues.insert(value);
        recoverTree(node->left, 2 * value + 1); // Recover left child
        recoverTree(node->right, 2 * value + 2); // Recover right child
    }

public:
    FindElements(TreeNode* root) {
        recoverTree(root, 0);
    }

    bool find(int target) {
        return recoveredValues.find(target) != recoveredValues.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */