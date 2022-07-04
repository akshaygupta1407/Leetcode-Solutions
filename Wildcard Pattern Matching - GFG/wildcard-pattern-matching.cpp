// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int helper(string s,string p,int n,int m,vector<vector<int>>&dp)
    {
        if(n<0 && m<0) return 1;
        if(m<0) return 0;
        if(n<0)
        {
            while(m>=0)
            {
                if(p[m]!='*')   return 0;
                m--;
            }
            return 1;
        }
        if(dp[n][m]!=-1)    return dp[n][m];
        if(p[m]=='*')
        {
            return dp[n][m] = helper(s,p,n-1,m,dp) || helper(s,p,n,m-1,dp);
        }
        else
        {
            if(s[n]!=p[m] && p[m]!='?') return dp[n][m] = 0;
            else    return dp[n][m] = helper(s,p,n-1,m-1,dp);
        }
    }
    int wildCard(string pattern,string str)
    {
        int n = str.length(), m = pattern.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(str,pattern,n,m,dp);
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends