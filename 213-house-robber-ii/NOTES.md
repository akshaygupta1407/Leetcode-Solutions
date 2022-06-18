```
class Solution {
public:
int house(vector<int>&nums,int n,vector<int>&dp)
{
if(n<0)
{
return 0;
}
if(n==0 || n==1)
{
return nums[n];
}
if(dp[n]!=-1)
{
return dp[n];
}
return dp[n] = nums[n] + max(house(nums,n-2,dp),house(nums,n-3,dp));
}
int rob(vector<int>& nums) {
if(nums.size()==1)
{
return nums[0];
}
vector<int>dp(nums.size(),-1);
vector<int>v1(nums.begin(),nums.end()-1);
vector<int>v2(nums.begin()+1,nums.end());
int op1 = max(house(v1,v1.size()-1,dp),house(v1,v1.size()-2,dp));
for(int i=0;i<dp.size();i++)
{
dp[i] = -1;
}
int op2 = max(house(v2,v2.size()-1,dp),house(v2,v2.size()-2,dp));
return max(op1,op2);
}
};
​
```