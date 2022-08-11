```
class Solution {
public:
bool Valid(TreeNode *root,long mn,long mx)
{
if(root==NULL)  return true;
if(root->val>=mx || root->val<=mn)  return false;
return Valid(root->left,mn,root->val) && Valid(root->right,root->val,mx);
}
bool isValidBST(TreeNode* root) {
long mn = LONG_MIN,mx = LONG_MAX;
return Valid(root,mn,mx);
}
};
```