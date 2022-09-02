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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            int n = s;
            double sum = 0;
            while(s--)
            {
                auto node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            sum = sum/n;
            ans.push_back(sum);
        }
        return ans;
    }
};