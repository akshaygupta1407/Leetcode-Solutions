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
    int preIdx = 0;
    TreeNode *construct(vector<int>& preorder, vector<int>& inorder,int start,int end)
    {
        if(start>end)
            return NULL;
        TreeNode *node = new TreeNode(preorder[preIdx++]);
        int pos;
        for(int i=start;i<=end;i++)
        {
            if(node->val==inorder[i])
            {
                pos = i;
                break;
            }
        }
        node->left = construct(preorder,inorder,start,pos-1);
        node->right = construct(preorder,inorder,pos+1,end);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(preorder,inorder,0,inorder.size()-1);
    }
};