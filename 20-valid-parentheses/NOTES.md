**M1**
```
class Solution {
public:
bool isValid(string s) {
stack<char>stack;
for(auto c : s)
{
switch(c)
{
case '(':
case '[':
case '{':   stack.push(c);
break;
case ')': if(!stack.empty() && stack.top()=='(')
stack.pop();
else
return false;
break;
case ']': if(!stack.empty() && stack.top()=='[')
stack.pop();
else
return false;
break;
case '}': if(!stack.empty() && stack.top()=='{')
stack.pop();
else
return false;
break;
}
}
if(!stack.empty())
return false;
return true;
}
};
```