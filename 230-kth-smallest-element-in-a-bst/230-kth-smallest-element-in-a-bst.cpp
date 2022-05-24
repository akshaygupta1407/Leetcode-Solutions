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
    int ans = 0;
    int m = 0;
    void dfs(TreeNode *root)
    {
        if(root==NULL || m<=0)  return;
        dfs(root->left);
        if(m==1)
        {
            ans = root->val;
        }
        m--;
        dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        m = k;
        dfs(root);
        return ans;
    }
};