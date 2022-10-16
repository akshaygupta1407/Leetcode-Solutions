class Solution {
public:
    int helper(vector<int>& jd,int i,int d,vector<vector<int>>&dp)
    {
        if(i>=jd.size() && d==0)
        {
            return 0;
        }
        if(d==0 || i>=jd.size())    return INT_MAX;
        if(dp[i][d]!=-1)    return dp[i][d];
        int currMax = jd[i];
        int mn = INT_MAX;
        for(int x = i;x<jd.size();x++)
        {
            currMax = max(currMax,jd[x]);
            int temp = helper(jd,x+1,d-1,dp);
            if(temp!=INT_MAX)
            {
                mn = min(mn,temp+currMax);
            }
        }
        return dp[i][d] = mn;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        return helper(jobDifficulty,0,d,dp);
    }
};