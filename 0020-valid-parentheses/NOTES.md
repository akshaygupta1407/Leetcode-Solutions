}
}
if(!stack.empty())
return false;
return true;
}
};
```
**M2**
```
class Solution {
public:
bool isValid(string s) {
stack<char>stack;
for(auto x : s)
{
if(stack.empty() || x=='(' || x=='[' || x=='{')
{
stack.push(x);
}
else
{
if((x==')' && stack.top()=='(') || (x=='}' && stack.top()=='{') || (x==']' && stack.top()=='['))
{
stack.pop();
}
else
{
return false;
}
}
}
if(!stack.empty())  return false;
return true;
}
};
```