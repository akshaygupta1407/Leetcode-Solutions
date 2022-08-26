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
    vector<vector<int>>res;
    int height(TreeNode *root)
    {
        if(root==NULL)  return -1;
        int lvl = max(height(root->left),height(root->right))+1;
        if(res.size()==lvl)  res.push_back({});
        res[lvl].push_back(root->val);
        return lvl;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        height(root);
        return res;
    }
};