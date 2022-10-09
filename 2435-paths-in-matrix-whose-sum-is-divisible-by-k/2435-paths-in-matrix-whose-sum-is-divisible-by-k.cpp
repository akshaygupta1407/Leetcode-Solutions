class Solution {
public:
    int mod = 1e9 + 7;
    int pathCountDPRecDP(vector<vector<int>>&mat, int m, int n, int k,long long sum,vector<vector<vector<long long>>>&dp)
    {
        if (m < 0 || n < 0 || k < 0) return 0;
        if (m==0 && n==0) return (sum%k==0);
        if(dp[m][n][sum%k]!=-1)   return dp[m][n][sum]%mod;
        long long r1=0,r2=0;
        if(m-1>=0)
        {
            r1 = pathCountDPRecDP(mat, m-1, n, k,(sum + mat[m-1][n])%k,dp)%mod;
        }
        if(n-1>=0)
        {
           r2 =  pathCountDPRecDP(mat, m, n-1, k, (sum + mat[m][n-1])%k,dp)%mod;
        }
        return dp[m][n][sum%k] = (r1 + r2)%mod;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<vector<long long>>>dp(m,vector<vector<long long>>(n,vector<long long>(k,-1)));
        return pathCountDPRecDP(grid,m-1,n-1,k,(grid[m-1][n-1])%k,dp);
    }
};