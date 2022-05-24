```
class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
unordered_map<int,int>m;
vector<int>res(2);
for(int i=0;i<nums.size();i++)
{
if(m.find(target-nums[i])!=m.end())
{
res[0] = i;
res[1] = m[target-nums[i]];
return res;
}
m[nums[i]] = i;
}
return res;
}
};
```