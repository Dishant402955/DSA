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
 pair<int ,TreeNode*>dfs(TreeNode* root){
    if(!root)return {0,nullptr};
    auto [d1,r1]=dfs(root->left);
    auto [d2,r2]=dfs(root->right);
    if(d1==d2)return {1+d1,root};
    else if(d1>d2) return {1+d1,r1};
    else
    return {1+d2,r2};
 }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
