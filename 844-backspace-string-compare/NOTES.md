**M1 using stack**
```
class Solution {
public:
bool backspaceCompare(string s, string t) {
stack<char>s1;
for(auto x : s)
{
if(x=='#' && !s1.empty())
{
s1.pop();
}
else if(x!='#')
{
s1.push(x);
}
}
s = "";
while(!s1.empty())
{
char c = s1.top();
s1.pop();
s+=c;
}
for(auto x : t)
{
if(x=='#' && !s1.empty())
{
s1.pop();
}
else if(x!='#')
{
s1.push(x);
}
}
t = "";
while(!s1.empty())
{
char c = s1.top();
s1.pop();
t+=c;
}
return s==t;
}
};
```