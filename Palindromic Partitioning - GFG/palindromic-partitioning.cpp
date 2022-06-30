// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    bool isPal(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    int Partition(string &s,int i,int j)
    {
        if(i>=j)    return 0;
        if(isPal(s,i,j))    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int ans = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int temp = 1 + Partition(s,i,k) + Partition(s,k+1,j);
            ans = min(ans,temp);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return Partition(str,0,str.length()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends