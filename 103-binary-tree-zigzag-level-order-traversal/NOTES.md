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
```