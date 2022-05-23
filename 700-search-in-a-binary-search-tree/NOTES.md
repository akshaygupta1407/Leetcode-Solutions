{
return it;
}
if(it->left!=NULL)
{
q.push(it->left);
}
if(it->right!=NULL)
{
q.push(it->right);
}
}
return NULL;
}
};
```
**M2**
```
class Solution {
public:
TreeNode* searchBST(TreeNode* root, int val) {
TreeNode *node = root;
while(node!=NULL && node->val!=val)
{
node = (node->val > val) ? node->left : node->right;
}
return node;
}
};
```
​
**M3**
```
class Solution {
public:
TreeNode* searchBST(TreeNode* root, int val) {
queue<TreeNode*>q;
q.push(root);
while(!q.empty())
{
TreeNode* it = q.front();