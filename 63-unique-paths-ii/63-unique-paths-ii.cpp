class Solution {
public:
    int dp[105][105];
    int dfs(int i,int j,vector<vector<int>>& obstacleGrid)
    {
        if(i<0 || i>=obstacleGrid.size() || j<0 || j>=obstacleGrid[0].size() || obstacleGrid[i][j]==1)
            return 0;
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1)
        {
            dp[i][j] = 1;
            return 1;
        }
        if(dp[i][j])    return dp[i][j];
        return dp[i][j] = dfs(i+1,j,obstacleGrid) + dfs(i,j+1,obstacleGrid); 
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int i=0,j=0;
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)  return 0;
        return dfs(0,0,obstacleGrid);
    }
};