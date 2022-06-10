```
class Solution {
public:
int lengthOfLongestSubstring(string s) {
int i=0,j=0;
int mx = 0;
unordered_set<char> hashset;
while(j<s.length())
{
if(hashset.find(s[j])==hashset.end())
{
hashset.insert(s[j]);
j++;
int l = hashset.size();
mx = max(mx,l);
}
else
{
hashset.erase(hashset.find(s[i]));
i++;
}
}
return mx;
}
};
```