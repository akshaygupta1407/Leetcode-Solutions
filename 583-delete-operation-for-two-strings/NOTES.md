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
​
```
class Solution {
public:
int dp[501][501];
​
int deletee(string &word1,string &word2,int i,int j)
{
if(i==word1.size() and j==word2.size())
{
return 0;
}
if(i==word1.size() or j==word2.size())
{
return max(word1.size()-i,word2.size()-j);
}
if(dp[i][j]!=-1)
{
return dp[i][j];
}
if(word1[i]==word2[j])
{
return deletee(word1,word2,i+1,j+1);
}
return dp[i][j]=1+min(deletee(word1,word2,i+1,j),deletee(word1,word2,i,j+1));
}
int minDistance(string &word1, string &word2) {
memset(dp,-1,sizeof(dp));
return deletee(word1,word2,0,0);
}
};
```