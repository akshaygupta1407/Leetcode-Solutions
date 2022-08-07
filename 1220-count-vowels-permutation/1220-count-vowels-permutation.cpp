class Solution {
public:
    int countVowelPermutation(int n) {
        if(n==1)
        {
            return 5;
        }
        vector<vector<long long>>dp(5,vector<long long>(n));
        dp[0][0]=1,dp[1][0]=1,dp[2][0]=1,dp[3][0]=1,dp[4][0]=1;
        long long mod = 1e9+7;
        for(int i=1;i<n;i++)
        {
            dp[0][i] = (dp[1][i-1] + dp[2][i-1] + dp[4][i-1])%mod;
            dp[1][i] = (dp[0][i-1] + dp[2][i-1])%mod;
            dp[2][i] = (dp[1][i-1] + dp[3][i-1])%mod;
            dp[3][i] = (dp[2][i-1])%mod;
            dp[4][i] = (dp[2][i-1] + dp[3][i-1])%mod;
        }
        long long sum = 0;
        sum = (dp[0][n-1]+dp[1][n-1]+dp[2][n-1]+dp[3][n-1]+dp[4][n-1])%mod;
        return (int)sum;
    }
};