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
    vector<vector<int>>ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)  return ans;
        queue<TreeNode *>q;
        q.push(root);
        int i = 0;
        while(!q.empty())
        {
            int size = q.size();
            i++;
            vector<int>res;
            while(size--)
            {
                TreeNode *node = q.front();
                q.pop();
                int no = node->val;
                res.push_back(no);
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            if(i%2==0)
            {
                reverse(res.begin(),res.end());
            }
            ans.push_back(res);
            
        }
        return ans;
    }
};