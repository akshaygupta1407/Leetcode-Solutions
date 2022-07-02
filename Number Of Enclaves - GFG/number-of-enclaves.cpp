// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int count = 0;
    bool isPossible(vector<vector<int>>& grid,int i,int j,int n,int m)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        if(grid[i][j]==0)
            return true;
        grid[i][j] = 0;
        count++;
        int a = isPossible(grid,i+1,j,n,m);
        int b = isPossible(grid,i,j+1,n,m);
        int c = isPossible(grid,i-1,j,n,m);
        int d = isPossible(grid,i,j-1,n,m);
        return a && b && c && d;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    count = 0;
                    if(isPossible(grid,i,j,n,m))
                    {
                        ans+=count;
                    }
                }
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}  // } Driver Code Ends