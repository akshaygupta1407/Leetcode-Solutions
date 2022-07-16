class Solution {
public:
    int dp[51][51][51];
    int mod = pow(10,9) + 7;
    int helper(int m, int n, int maxMove, int i, int j)
    {
        if(i<0 || j<0 || i>=m || j>=n)  return 1;
        if(maxMove==0)  return 0;
        if(dp[i][j][maxMove]!=-1)   return dp[i][j][maxMove];
        int ans = 0;
        ans = (ans + helper(m,n,maxMove-1,i+1,j))%mod;
        ans = (ans + helper(m,n,maxMove-1,i-1,j))%mod;
        ans = (ans + helper(m,n,maxMove-1,i,j+1))%mod;
        ans = (ans + helper(m,n,maxMove-1,i,j-1))%mod;
        dp[i][j][maxMove] = ans;
        return dp[i][j][maxMove]%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return helper(m,n,maxMove,startRow,startColumn);
    }
};