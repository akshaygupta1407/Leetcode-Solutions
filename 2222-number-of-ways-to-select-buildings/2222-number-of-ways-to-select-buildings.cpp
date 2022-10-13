class Solution {
public:
    long long numberOfWays(string s) {
        long int dp[4][2] = {};
        dp[0][0] = 1,dp[0][1] = 1;
        for(int i=0;i<s.length();i++)
        {
            for(int j=1;j<=3;j++)
            {
                dp[j][s[i]-'0'] += dp[j-1][1-(s[i]-'0')];
            }
        }
        return dp[3][0] + dp[3][1];
    }
};