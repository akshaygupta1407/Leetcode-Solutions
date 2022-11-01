class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>result(grid[0].size(),0);
        for(int col=0;col<grid[0].size();col++)
        {
            int currentcol = col;
            for(int row=0;row<grid.size();row++)
            {
                int nextcol = currentcol + grid[row][currentcol];
                if(nextcol<0 || nextcol>grid[0].size()-1 || grid[row][currentcol]!=grid[row][nextcol])
                {
                    result[col] = -1;
                    break;
                }
                result[col] = nextcol;
                currentcol = nextcol;
            }
        }
        return result;
    }
};