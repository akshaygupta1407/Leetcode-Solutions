// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  bool isPossible(int boards[],int n,int k,long long mid)
    {
        long long painter = 1,currsum = 0;
        for(int i=0;i<n;i++)
        {
            if(boards[i]>mid)
                return false;
            else if(boards[i] + currsum > mid)
            {
                painter++;
                if(painter > k)
                    return false;
                currsum = boards[i];
            }
            else
            {
                currsum+=boards[i];
            }
        }
        return true;
    }
    long long minTime(int boards[], int n, int k)
    {
        // code here
        // return minimum time
        long long s = 0,e = 0;
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=boards[i];
        }
        e = sum;
        long long ans = -1;
        while(s<=e)
        {
            long long mid = s + (e-s)/2;
            if(isPossible(boards,n,k,mid))
            {
                ans = mid;
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends