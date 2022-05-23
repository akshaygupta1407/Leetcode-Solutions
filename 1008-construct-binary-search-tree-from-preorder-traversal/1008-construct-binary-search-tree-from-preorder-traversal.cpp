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
    TreeNode *helper(vector<int>& preorder,int s, int e)
    {
        if(s>e) return NULL;
        TreeNode *root = new TreeNode(preorder[s]);
        int pos = s;
        for(int i=s+1;i<=e;i++)
        {
            if(preorder[i]<root->val)
                pos = i;
            else
                break;
        }
        root->left = helper(preorder,s+1,pos);
        root->right = helper(preorder,pos+1,e);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size()-1);
    }
};