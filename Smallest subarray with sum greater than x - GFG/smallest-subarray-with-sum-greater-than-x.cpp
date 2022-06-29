// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int sum = 0;
        int i=0,j=0;
        int count = 0,mx = INT_MAX;
        while(i<n && j<n)
        {
            while(sum<=x && j<n)
            {
                sum+=arr[j];
                j++;
                count++;
                if(sum>x)
                {
                    mx = min(mx,count);
                }
            }
            while(sum>x && i<n)
            {
                sum-=arr[i];
                i++;
                count--;
                if(sum>x)
                {
                    mx = min(mx,count);
                }
            }
        }
        while(sum>x && i<n)
        {
            sum-=arr[i];
            i++;
            count--;
            if(sum>x)
            {
                mx = min(mx,count);
            }
        }
        return mx;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends