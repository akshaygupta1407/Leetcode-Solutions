class Solution {
public:
    bool possible(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,int m,int n)
    {
        if(i<0 || j<0 || i>=m || j>=n || (grid1[i][j]==0 && grid2[i][j]==0) || (grid1[i][j]==1 && grid2[i][j]==0))
            return true;
        if(grid1[i][j]==1 && grid2[i][j]==1)
        {
            grid1[i][j] = 0;
            grid2[i][j] = 0;
        }
        else if(grid1[i][j]==0 && grid2[i][j]==1)
            return false;
        bool a = possible(grid1,grid2,i+1,j,m,n);
        bool b = possible(grid1,grid2,i,j+1,m,n);
        bool c = possible(grid1,grid2,i,j-1,m,n);
        bool d = possible(grid1,grid2,i-1,j,m,n);
        return a && b && c && d;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(),n = grid2[0].size();
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid1[i][j]==1 && grid2[i][j]==1)
                {
                    if(possible(grid1,grid2,i,j,m,n))
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};