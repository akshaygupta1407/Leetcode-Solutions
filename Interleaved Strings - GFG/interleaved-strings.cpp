// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool check(string A,int i, string B,int j, string C,int k,vector<vector<int>>&dp)
    {
        if(i==A.length())
        {
            return B.substr(j)==C.substr(k);
        }
        if(j==B.length())
        {
            return A.substr(i)==C.substr(k);
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        // bool ans = false;
        // if(C[k]==A[i] && check(A,i+1,B,j,C,k+1,dp) || )
        return dp[i][j] = ((C[k]==A[i] && check(A,i+1,B,j,C,k+1,dp)) ||  (C[k]==B[j] && check(A,i,B,j+1,C,k+1,dp)));
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        if(A.length() + B.length() != C.length())   return false;
        vector<vector<int>>dp(A.length()+1,vector<int>(B.length()+1,-1));
        return check(A,0,B,0,C,0,dp);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends