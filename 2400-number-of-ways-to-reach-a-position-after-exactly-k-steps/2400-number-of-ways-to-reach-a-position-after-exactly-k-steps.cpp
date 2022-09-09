class Solution {
public:
    int mod=1e9+7;
    int dp[3005][1005];
    int dfs(int startPos, int endPos, int k)
    {
        if(startPos==endPos && k==0)
        {
            return 1;
        }
        if(k<=0)
        {
            return 0;
        }
        if(dp[startPos+1000][k]!=-1)
        {
            return dp[startPos+1000][k];
        }
        int f = dfs(startPos+1,endPos,k-1);
        int b = dfs(startPos-1,endPos,k-1);
        int ans = (f+b)%mod;
        return dp[startPos+1000][k] =  ans;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        if(abs(endPos-startPos)>k){
        return 0;
    }
        memset(dp,-1,sizeof(dp));
        return dfs(startPos,endPos,k);
    }
};