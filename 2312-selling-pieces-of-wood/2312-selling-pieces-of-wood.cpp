class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));
        for(auto x : prices)
        {
            dp[x[0]][x[1]] = x[2];
        }
        for(long long i=1;i<=m;i++)
        {
            for(long long j=1;j<=n;j++)
            {
                for(long long k=0;k<=i;k++)
                {
                    dp[i][j] = max(dp[i][j],dp[i-k][j] + dp[k][j]);
                }
                for(long long k=0;k<=j;k++)
                {
                    dp[i][j] = max(dp[i][j],dp[i][j-k] + dp[i][k]);
                }
            }
        }
        return dp[m][n];
    }
};