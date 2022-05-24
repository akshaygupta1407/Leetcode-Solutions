```
class Solution {
public:
stack<int> stack;
int longestValidParentheses(string s) {
int mx = 0;
stack.push(-1);
for(int i=0;i<s.length();i++)
{
if(s[i]=='(')
{
stack.push(i);
}
else
{
if(!stack.empty())
{
stack.pop();
}
if(!stack.empty())
{
mx = max(mx,i-stack.top());
}
else
{
stack.push(i);
}
}
}
return mx;
}
};
```