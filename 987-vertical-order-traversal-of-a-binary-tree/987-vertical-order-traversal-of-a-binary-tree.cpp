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
    map<int,map<int,multiset<int>>>map;
    void dfs(TreeNode *root,int x,int y)
    {
        if(!root)
            return;
        map[y][x].insert(root->val);
        dfs(root->left,x+1,y-1);
        dfs(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);  //x,y
        vector<vector<int>>res;
        for(auto x : map)
        {
            vector<int>curr;
            for(auto y : x.second)
            {
                for(auto z : y.second)
                {
                    curr.push_back(z);
                }
            }
            res.push_back(curr);
        }
        return res;
    }
};