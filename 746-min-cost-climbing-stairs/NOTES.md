**Top Down**
```
class Solution {
public:
int mincost(vector<int>& cost,int n,vector<int>&dp)
{
if(n<0) return 0;
if(n<=1)    return dp[n] = cost[n];
if(dp[n]!=-1)
return dp[n];
return dp[n] = cost[n] + min(mincost(cost,n-1,dp),mincost(cost,n-2,dp));
}
int minCostClimbingStairs(vector<int>& cost) {
int n = cost.size();
vector<int>dp(n,-1);
return min(mincost(cost,n-1,dp), mincost(cost,n-2,dp));
}
};
```