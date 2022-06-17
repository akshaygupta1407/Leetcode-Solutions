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
    int camera = 0;
    int dfs(TreeNode *root)
    {
        if(root==NULL)  return 1;
        int L = dfs(root->left);
        int R = dfs(root->right);
        
        if(L==1 && R==1)    return 2;
        if(L==2 || R==2)
        {
            camera++;
            return 3;
        }
        return 1;
    }
    int minCameraCover(TreeNode* root) {
        if(root==NULL) return 0;
        int v = dfs(root);
        return camera + (v==2 ? 1 : 0);
    }
};