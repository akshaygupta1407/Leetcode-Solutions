class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        vector<vector<int>>direction = {{1,0},{0,1},{-1,0},{0,-1}};
        int m = mat.size(),n = mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                }
                else
                {
                    mat[i][j] = -1; 
                }
            }
        }
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int r = node.first,c = node.second;
            for(auto dir : direction)
            {
                int currx = r + dir[0];
                int curry = c + dir[1];
                if(currx<0 || curry<0 || currx>=m || curry>=n || mat[currx][curry]!=-1)
                    continue;
                mat[currx][curry] = mat[r][c]+1;
                q.push({currx,curry});
            }
        }
        return mat;
    }
};