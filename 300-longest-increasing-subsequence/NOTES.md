**M1**
```
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
int n = nums.size();
vector<int>dp(n,1);
for(int i=1;i<n;i++)
{
for(int j=0;j<i;j++)
{
if(nums[i]>nums[j])
{
dp[i] = max(dp[i],dp[j]+1);
}
}
}
return *max_element(dp.begin(),dp.end());
}
};
```
**M2**
```
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
int n = nums.size();
vector<int>lis;
for(int i=0;i<n;i++)
{
int ele = nums[i];
int idx = lower_bound(lis.begin(),lis.end(),ele) - lis.begin();
if(idx>=lis.size()) lis.push_back(ele);
else lis[idx] = ele;
}
return lis.size();
}
};
```