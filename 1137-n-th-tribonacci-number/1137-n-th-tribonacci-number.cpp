class Solution {
public:
    int trif(int n,vector<int>&dp)
    {
        if(n==0)    return dp[n] = 0;
        if(n==1 || n==2) return dp[n] = 1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = trif(n-1,dp) + trif(n-2,dp) + trif(n-3,dp);
    }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return trif(n,dp);
    }
};