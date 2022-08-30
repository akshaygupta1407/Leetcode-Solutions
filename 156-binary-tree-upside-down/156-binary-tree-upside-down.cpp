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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root==NULL || root->left==NULL)  return root;
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        TreeNode *newroot = upsideDownBinaryTree(root->left);
        l->right = root;
        l->left = r;
        root->left = NULL;
        root->right = NULL;
        return newroot;
    }
};