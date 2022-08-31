class Solution {
public:
    void dfs(vector<vector<int>>&heights,int i,int j,vector<vector<bool>>&visited)
    {
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size() || visited[i][j]==true)
            return;
        visited[i][j] = true;
        if(i+1<heights.size() && heights[i+1][j]>=heights[i][j])
        {
            dfs(heights,i+1,j,visited);
        }
        if(j+1<heights[0].size() && heights[i][j+1]>=heights[i][j])
        {
            dfs(heights,i,j+1,visited);
        }
        if(i-1>=0 && heights[i-1][j]>=heights[i][j])
        {
            dfs(heights,i-1,j,visited);
        }
        if(j-1>=0 && heights[i][j-1]>=heights[i][j])
        {
            dfs(heights,i,j-1,visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>res;
        int m = heights.size(),n = heights[0].size();
        vector<vector<bool>>pacific(m,vector<bool>(n,false)),atlantic(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            dfs(heights,i,0,pacific);
            dfs(heights,i,n-1,atlantic);
        }
        for(int i=0;i<n;i++)
        {
            dfs(heights,0,i,pacific);
            dfs(heights,m-1,i,atlantic);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};