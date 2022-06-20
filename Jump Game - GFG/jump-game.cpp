// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int n) {
        // code here
        if(n<=1)    return true;
        if(A[0]==0) return false;
        int maxreach = A[0],steps = A[0],jump = 1;
        for(int i=1;i<n;i++)
        {
            if(i==n-1)  return true;
            maxreach = max(maxreach,i+A[i]);
            steps--;
            if(steps==0)
            {
              jump++;
              if(i>=maxreach)   return false;
              steps = maxreach - i;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends