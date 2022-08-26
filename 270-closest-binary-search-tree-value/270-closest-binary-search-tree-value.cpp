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
    map<double,int>mpp;
    void dfs(TreeNode *root,double target)
    {
        if(root==NULL)  return;
        mpp[abs(root->val-target)] = root->val;
        // cout<<abs(root->val-target)<<endl;
        dfs(root->left,target);
        dfs(root->right,target);
    }
    int closestValue(TreeNode* root, double target) {
        if(root==NULL)  return 0;
        dfs(root,target);
        for(auto x : mpp)
        {
            int a = x.second;
            return a;
        }
        return 0;
    }
};