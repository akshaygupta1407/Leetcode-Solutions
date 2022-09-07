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
    string res  ="";
    void dfs(TreeNode *root)
    {
        if(root==NULL)  
        {
            return;
        }
        res+="(";
        res+=to_string(root->val);
         if(root -> left == NULL && root -> right)
        {
            res += "()";
        }
        dfs(root->left);
        dfs(root->right);
        res+=")";
    }
    string tree2str(TreeNode* root) {
        if(root==NULL)  return res;
        dfs(root);
        return res.substr(1, res.size() - 2);
    }
};