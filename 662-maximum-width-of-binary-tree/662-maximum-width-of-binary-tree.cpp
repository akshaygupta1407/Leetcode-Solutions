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
        if(root==NULL)
            return 0;
        queue<pair<TreeNode *,int>>q;
        q.push({root,0});
        int res = 1;
        while(!q.empty())
        {
            int count = q.size();
            int start = q.front().second;
            int end = q.back().second;
            res = max(res,end-start+1);
            while(count--)
            {
                auto p = q.front();
                q.pop();
                int index = p.second-start;
                if(p.first->left!=NULL)
                {
                    q.push({p.first->left,(long long)2*index+1});
                }
                if(p.first->right!=NULL)
                {
                    q.push({p.first->right,(long long)2*index+2});
                }
            }
        }
        return res;
    }
};