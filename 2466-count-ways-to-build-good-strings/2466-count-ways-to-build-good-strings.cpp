class Solution {
public:
    int mod = 1e9+7;
    int helper(int n,int zero,int one,vector<int>&dp)
    {
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int w1 = helper(n-zero,zero,one,dp);
        int w2 = helper(n-one,zero,one,dp);
        return dp[n] = (w1 + w2)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int total = 0;
        vector<int>dp(high+1,-1);
        for(int i=low;i<=high;i++)
        {
            total = (total + helper(i,zero,one,dp))%mod;
        }
        return total;
    }
};