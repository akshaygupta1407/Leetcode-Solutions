class Solution {
public:
    int helper(string s,int i, int n,vector<int>&dp)
    {
        if(i==n)    return 1;
        if(s[i]=='0')   return 0;
        if(dp[i]!=-1) return dp[i];
        int res = helper(s,i+1,n,dp);
        if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6')))    res+= helper(s,i+2,n,dp);
        return dp[i] = res;
    }
    int numDecodings(string s) {
        if(s.empty())   return 0;
        int n = s.length();
        vector<int>dp(n+1,-1);
        return helper(s,0,n,dp);
    }
};