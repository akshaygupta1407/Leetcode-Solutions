class Solution {
public:
    vector<pair<int,int>>v1,v2;
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1)
            return;
        if(grid[i][j]==1)
        {
            grid[i][j] = 2;
        }
        dfs(grid,i+1,j,n,m);
        dfs(grid,i,j+1,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j-1,n,m);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,n,m);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    v1.push_back({i,j});
                else if(grid[i][j]==2)
                    v2.push_back({i,j});
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<v1.size();i++)
        {
            for(int j=0;j<v2.size();j++)
            {
                int r = abs(v1[i].first - v2[j].first);
                int c = abs(v1[i].second - v2[j].second);
                ans = min(ans,r+c-1);
            };
        }
        return ans;
    }
};