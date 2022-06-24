```
class Solution {
public:
vector<vector<string>>res;
bool palindrome(string &s,int lo,int hi)
{
while(lo<hi)
{
if(s[lo++]!=s[hi--])
{
return false;
}
}
return true;
}
void backtrack(string s,int start,vector<string>&curr)
{
if(start==s.length())
{
res.push_back(curr);
return;
}
for(int i=start;i<s.length();i++)
{
if(palindrome(s,start,i))
{
curr.push_back(s.substr(start,i-start+1));
backtrack(s,i+1,curr);
curr.pop_back();
}
}
}
vector<vector<string>> partition(string s) {
vector<string>ans;
backtrack(s,0,ans);
return res;
}
};
​
```