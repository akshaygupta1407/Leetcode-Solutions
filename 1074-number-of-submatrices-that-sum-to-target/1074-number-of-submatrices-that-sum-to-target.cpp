class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] + matrix[i-1][j-1] - dp[i-1][j-1];
            }
        }
        int count = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int k=i;k<=n;k++)
                {
                    for(int l=j;l<=m;l++)
                    {
                        int ans = dp[i-1][j-1] + dp[k][l] - dp[i-1][l] - dp[k][j-1];
                        if(ans==target) count++;
                    }
                }
            }
        }
        return count;
    }
};