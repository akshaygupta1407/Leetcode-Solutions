```
class Solution {
public:
int minDistance(string word1, string word2) {
int l1 = word1.length(),l2 = word2.length();
vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
int c=0;
for(int i=1;i<=l1;i++)
{
for(int j=1;j<=l2;j++)
{
dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]);
if(word1[i-1]==word2[j-1])
{
for(int k=1;k<j;k++)
{
c = max(c,dp[i-1][k]);
}
dp[i][j] = dp[i][j] + c + 1;
}
else
{
dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]);
}
}
}
int mx = 0;
for(int i=1;i<=l1;i++)
{
for(int j=1;j<=l2;j++)
{
cout<<dp[i][j]<<" ";
mx = max(mx,dp[i][j]);
}
cout<<endl;
}
cout<<endl;
return l1 + l2 - 2*mx;
}
};
```