class Solution {
public:
    int climb(vector<int>& cost,int n,vector<int>&dp)
    {
        if(n<0) return 0;
        if(n<=1)    return dp[n] = cost[n];
        if(dp[n]!=-1)   return dp[n];
        return dp[n] = cost[n] + min(climb(cost,n-1,dp),climb(cost,n-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(climb(cost,n-1,dp),climb(cost,n-2,dp));
    }
};