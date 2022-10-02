class Solution {
public:
    int func(int n,int k,int target,vector<vector<long long>>&dp)
    {
        if(target==0 && n==0)   return 1;
        if(target<=0 || n<=0)   return 0;
        if(dp[n][target]!=-1)   return dp[n][target];
        int consider = 0;
        for(int i=1;i<=k;i++)
        {
            consider = (consider%1000000007 + func(n-1,k,target-i,dp) % 1000000007)%1000000007;
        }
        return dp[n][target] = consider;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>>dp(n+1,vector<long long>(target+1,-1));
        return func(n,k,target,dp);
    }
};