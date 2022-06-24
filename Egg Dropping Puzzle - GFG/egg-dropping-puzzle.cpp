// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int egg(int n,int k,vector<vector<int>>&dp)
    {
        if(k<=1)    return k;
        if(n==1)    return k;
        if(dp[n][k]!=-1)    return dp[n][k];
        int mn = INT_MAX,x,res;
        for(x=1;x<=k;x++)
        {
            res = max(egg(n-1,x-1,dp),egg(n,k-x,dp));
            mn = min(mn,res);
        }
        return dp[n][k] =  mn + 1;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(500,vector<int>(500,-1));
        return egg(n,k,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends