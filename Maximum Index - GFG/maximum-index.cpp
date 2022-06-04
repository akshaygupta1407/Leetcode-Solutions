// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        vector<int>Leftmn(n),Rightmx(n);
        Leftmn[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            Leftmn[i] = min(Leftmn[i-1],arr[i]);
        }
        Rightmx[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            Rightmx[i] = max(Rightmx[i+1],arr[i]);
        }
        int i=0,j=0;
        int mx = -1;
        while(i<n && j<n)
        {
            if(Leftmn[i]<=Rightmx[j])
            {
                mx = max(mx,j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return mx;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends