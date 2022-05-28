```
class Solution {
public:
bool digitCount(string nums) {
map<char,int>m;
for(auto x : nums)
{
m[x-'0']++;
cout<<x-'0'<<endl;
}
for(int i=0;i<nums.size();i++)
{
if(nums[i]=='0' && m.find(i)!=m.end())  return false;
else if(nums[i]!='0' && (m.find(i)==m.end() || m[i]!=(nums[i]-'0')))    return false;
}
return true;
}
};
```