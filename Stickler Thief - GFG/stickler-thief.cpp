// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int cost(int arr[], int n,vector<int>&dp)
    {
        if(n<0) return 0;
        if(n==0 || n==1)    return dp[n] = arr[n];
        if(dp[n]!=-1)   return dp[n];
        return dp[n] = arr[n] + max(cost(arr,n-2,dp),cost(arr,n-3,dp));
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n+1,-1);
        return max(cost(arr,n-1,dp),cost(arr,n-2,dp));
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends