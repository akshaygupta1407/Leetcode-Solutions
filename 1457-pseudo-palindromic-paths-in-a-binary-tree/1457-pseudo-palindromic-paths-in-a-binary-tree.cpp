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
    vector<int>res;
    int ans = 0;
    bool isPalindrome()
    {
        int odd=0;
        for(auto x : res)
        {
            if(x%2!=0)  odd++;
        }
        return odd<=1;
    }
    void dfs(TreeNode *root)
    {
        if(root==NULL)  return;
        res[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            if(isPalindrome())  ans++;
        }
        else
        {
            dfs(root->left);
            dfs(root->right);
        }
        res[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        res.resize(10,0);
        dfs(root);
        return ans;
    }
};