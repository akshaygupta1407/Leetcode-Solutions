class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int steps = 0;
        int m = grid.size(),n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i-1,j});
                    q.push({i,j-1});
                    q.push({i+1,j});
                    q.push({i,j+1});
                }
            }
        }
        while(!q.empty())
        {
            int s = q.size();
            steps++;
            while(s--)
            {
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(i>=0 && j>=0 && i<m && i<n && grid[i][j]==0)
                {
                    grid[i][j] = steps;
                    q.push({i-1,j});
                    q.push({i,j-1});
                    q.push({i+1,j});
                    q.push({i,j+1});
                }
            }
        }
        return steps == 1 ? -1 : steps-1;
    }
};