// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool possible(int A[],int n,int m,int currmin)
    {
        int student = 1, currsum = 0;
        for(int i=0;i<n;i++)
        {
            if(A[i]>currmin)    return false;
            if(currsum + A[i] > currmin)
            {
                student++;
                currsum = A[i];
                if(student>m)   return false;
            }
            else
            {
                currsum+=A[i];
            }
        }
        return true;
    }
    int findPages(int A[], int n, int m) 
    {
        //code here
        if(m>n) return -1;
        int start = 0,end = 0;
        for(int i=0;i<n;i++)
        {
            end+=A[i];
        }
        int res = INT_MAX;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(possible(A,n,m,mid))
            {
                res = min(res,mid);
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends