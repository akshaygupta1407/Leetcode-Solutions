```
class Solution {
public:
int ans = 0;
int m = 0;
void dfs(TreeNode *root)
{
if(root==NULL) return;
if(m>0)
dfs(root->left);
if(m==1)
{
ans = root->val;
}
m--;
if(m>0)
dfs(root->right);
}
int kthSmallest(TreeNode* root, int k) {
m = k;
dfs(root);
return ans;
}
};
```