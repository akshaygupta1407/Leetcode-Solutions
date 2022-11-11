class Solution {
public:
    long long helper(vector<int>& robot, vector<int>&v,int n,int m,int i,int j,vector<vector<long long>>&dp)
    {
        if(i==n) return 0;
        if(j==m) return 1e16;
        if(dp[i][j]!=-1) return dp[i][j];
        long long take = (long long)(abs(robot[i]-v[j]) + helper(robot,v,n,m,i+1,j+1,dp));
        long long skip = helper(robot,v,n,m,i,j+1,dp);
        return dp[i][j] = min(take,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int>v;
        for(auto x : factory)
        {
            int i = x[0],j = x[1];
            for(int k=0;k<j;k++)
            {
                v.push_back(i);
            }
        }
        int n = robot.size();
        int m = v.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
        return helper(robot,v,n,m,0,0,dp);
    }
};