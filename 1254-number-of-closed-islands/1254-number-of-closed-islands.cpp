class Solution {
public:
    bool isPossible(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m)
        {
            return false;
        }
        if(grid[i][j]==1)
            return true;
        grid[i][j]=1;
        bool a = isPossible(grid,i+1,j,n,m);
        bool b = isPossible(grid,i,j+1,n,m);
        bool c = isPossible(grid,i-1,j,n,m);
        bool d = isPossible(grid,i,j-1,n,m);
        return a && b && c && d;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0 && isPossible(grid,i,j,n,m))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};