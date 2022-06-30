// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long>st;
        long long mxArea = 0;
        for(int i=0;i<=n;i++)
        {
            long long currHeight = i==n ? 0 : arr[i];
            while(!st.empty() && currHeight < arr[st.top()])
            {
                long long tp = st.top();
                st.pop();
                long long width = st.empty() ? i : i - st.top() - 1;
                long long area = arr[tp]*width;
                mxArea = max(area,mxArea);
            }
            st.push(i);
        }
        return mxArea;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends