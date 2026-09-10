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
class Solution {
public:
    pair<int,int> ok(TreeNode* root, int &ans) {

        if(root == NULL) {
            return {0,0};
        }

        pair<int,int> l = ok(root->left, ans);
        pair<int,int> r = ok(root->right, ans);

        int sum = r.first + l.first + root->val;
        int n = r.second + l.second + 1;
        
        if(sum / n == root->val) {
            ans++;
        }
    
        return {sum, n};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        ok(root, ans);
        return ans;
    }
};
``
