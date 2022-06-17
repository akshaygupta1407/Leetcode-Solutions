// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int helper(string s, string t,int n,int m,vector<vector<int>>&dp)
  {
      if(n==0)  return m;
      if(m==0)  return n;
      if(dp[n][m]!=-1)  return dp[n][m];
      if(s[n-1]==t[m-1])
        return dp[n][m] = helper(s,t,n-1,m-1,dp);
      else
      {
          int insert,del,replace;
          insert = helper(s,t,n,m-1,dp);
          del = helper(s,t,n-1,m,dp);
          replace = helper(s,t,n-1,m-1,dp);
          return dp[n][m] = min(insert,min(del,replace))+1;
      }
  }
    int editDistance(string s, string t) {
        // Code here
        int n = s.length(),m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(s,t,n,m,dp);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends