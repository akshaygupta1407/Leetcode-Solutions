```
class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
map<int,int>m;
int cum = 0,cnt = 0;
m[0]++;
for(int i=0;i<nums.size();i++)
{
cum+=nums[i];
cnt+=m[cum-k];
m[cum]++;
}
return cnt;
}
};
```