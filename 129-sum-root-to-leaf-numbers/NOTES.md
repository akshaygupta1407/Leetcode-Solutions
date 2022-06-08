**M1**
```
class Solution {
public:
int sum = 0;
void dfs(TreeNode *root,string curr)
{
if(root==NULL)
return;
if(root->left==NULL && root->right==NULL)
{
char ch = root->val + '0';
curr+=ch;
sum+=stoi(curr);
return;
}
char ch = root->val + '0';
dfs(root->left,curr + ch);
dfs(root->right,curr + ch);
curr.pop_back();
}
int sumNumbers(TreeNode* root) {
dfs(root,"");
return sum;
}
};
```
**M2**
```
class Solution {
public:
int dfs(TreeNode *root,int sum)
{
if(root==NULL)
return 0;
if(root->left==NULL && root->right==NULL)
{
return sum*10 + root->val;
}
return dfs(root->left,sum*10 + root->val) + dfs(root->right,sum*10 + root->val);
}
int sumNumbers(TreeNode* root) {
return dfs(root,0);
}
};
```