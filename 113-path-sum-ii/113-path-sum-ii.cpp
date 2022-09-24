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
    void solve(TreeNode *root, int targetsum,int sum,vector<int>&path)
    {
        if(root==NULL)  return;
        sum+=root->val;
        path.push_back(root->val);
        if(sum==targetsum && root->left==NULL && root->right==NULL)
        {
            res.push_back(path);
        }
        solve(root->left,targetsum,sum,path);
        solve(root->right,targetsum,sum,path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)  return res;
        vector<int>path;
        solve(root,targetSum,0,path);
        return res;
        
    }
};