class Solution {
public:
    int dfs(vector<vector<int>> &grid,int i,int j,int n,int m)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        return dfs(grid,i+1,j,n,m) + dfs(grid,i,j+1,n,m) + dfs(grid,i-1,j,n,m) + dfs(grid,i,j-1,n,m) + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans = max(ans,dfs(grid,i,j,n,m));
                }
            }
        }
        return ans;
    }
};