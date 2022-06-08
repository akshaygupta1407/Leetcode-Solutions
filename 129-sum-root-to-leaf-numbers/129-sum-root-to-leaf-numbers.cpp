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
    vector<string>res;
    int sum = 0;
    void dfs(TreeNode *root,string curr)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            char ch = root->val + '0';
            curr+=ch;
            // res.push_back(curr);
            sum+=stoi(curr);
            return;
        }
        // int val = root->val;
        // curr.push_back(val+'0');
        char ch = root->val + '0';
        dfs(root->left,curr + ch);
        dfs(root->right,curr + ch);
        curr.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,"");
        // for(auto x : res)
        // {
        //     cout<<x<<endl;
        // }
        return sum;
    }
};