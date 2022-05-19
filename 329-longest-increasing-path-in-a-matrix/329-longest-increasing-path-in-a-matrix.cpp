class Solution {
public:
    int dp[201][201];
    int dfs(vector<vector<int>>& matrix,int i,int j,int pre)
    {
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || pre>=matrix[i][j])
            return 0;
        if(dp[i][j])    return dp[i][j];
        int l = dfs(matrix,i,j-1,matrix[i][j]);
        int r = dfs(matrix,i,j+1,matrix[i][j]);
        int u = dfs(matrix,i-1,j,matrix[i][j]);
        int d = dfs(matrix,i+1,j,matrix[i][j]);
        return dp[i][j] = max(l,max(r,max(u,d)))+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mx = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mx = max(mx,dfs(matrix,i,j,-1));
            }
        }
        return mx;
    }
};