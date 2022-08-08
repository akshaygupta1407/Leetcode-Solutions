class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    long long int mod = 1e9+7;
    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())   return 0;
        if(dp[i][j]!=0) return dp[i][j];
        int ans = 1;
        for(int k=0;k<4;k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]>grid[i][j])
            {
                ans = (ans%mod + dfs(grid,x,y,dp)%mod)%mod;
            }
        }
        return dp[i][j] = ans%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        // vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<vector<int>>dp(m,vector<int>(n,0));
        long long int sum=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum = (sum%mod + dfs(grid,i,j,dp)%mod)%mod;
            }
        }
        return sum%mod;
    }
};