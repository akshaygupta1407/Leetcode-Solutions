class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        vector<vector<int>>dir = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};;
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int x = node.first, y = node.second;
            if(x==n-1 && y==n-1)
                return grid[x][y];
            for(auto d : dir)
            {
                int currx = x + d[0];
                int curry = y + d[1];
                if(currx>=0 && curry>=0 && currx<n && curry<n && grid[currx][curry]==0)
                {
                    grid[currx][curry] = grid[x][y] + 1;
                    q.push({currx,curry});
                }
            }
        }
        return -1;
    }
};