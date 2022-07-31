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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)  return 0;
        int res = 1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            res = max(res,end-start+1);
            while(size--)
            {
                auto node = q.front();
                q.pop();
                int index = node.second;
                if(node.first->left)
                {
                    q.push({node.first->left,(long long)2*index+1});
                }
                if(node.first->right)
                {
                    q.push({node.first->right,(long long)2*index+2});
                }
            }
        }
        return res;
    }
};