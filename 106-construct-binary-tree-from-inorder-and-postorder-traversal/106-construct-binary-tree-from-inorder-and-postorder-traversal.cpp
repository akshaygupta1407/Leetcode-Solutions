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
    int postIdx = 0;
    TreeNode *construct(vector<int>& inorder, vector<int>& postorder,int start,int end)
    {
        if(start>end)   return NULL;
        TreeNode *node = new TreeNode(postorder[postIdx--]);
        int pos;
        for(int i=start;i<=end;i++)
        {
            if(node->val==inorder[i])
            {
                pos = i;
                break;
            }
        }
        node->right = construct(inorder,postorder,pos+1,end);
        node->left = construct(inorder,postorder,start,pos-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIdx = postorder.size()-1;
        return construct(inorder,postorder,0,inorder.size()-1);
    }
};