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
    bool dfs(TreeNode *root,long mn,long mx)
    {
        if(root==NULL)  return true;
        if(root->val >= mx || root->val<=mn)    return false;
        return dfs(root->left,mn,root->val) && dfs(root->right,root->val,mx);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)  return true;
        long mn = LONG_MIN,mx=LONG_MAX;
        return dfs(root,mn,mx);
    }
};