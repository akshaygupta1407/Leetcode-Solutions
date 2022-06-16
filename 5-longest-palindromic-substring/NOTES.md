```
class Solution {
public:
string checkfrommiddle(string s,int i,int j)
{
while(i>=0 && j<s.length() && s[i]==s[j])
{
i--;
j++;
}
return s.substr(i+1,j-i-1);
}
string longestPalindrome(string s) {
if(s.length()==1)
return s;
string res;
for(int i=0;i<s.length();i++)
{
string s1 = checkfrommiddle(s,i,i);
string s2 = checkfrommiddle(s,i,i+1);
if(s1.length()>res.length())
res = s1;
if(s2.length()>res.length())
res = s2;
}
return res;
}
};
​
​
```