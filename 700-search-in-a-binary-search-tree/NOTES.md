**M1**
```
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
TreeNode* searchBST(TreeNode* root, int val) {
queue<TreeNode*>q;
q.push(root);
while(!q.empty())
{
TreeNode* it = q.front();
q.pop();
if(it->val==val)
{
return it;
}
if(it->left!=NULL)
{
q.push(it->left);
}