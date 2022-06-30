// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int histo(vector<int>&heights,int n)
  {
      stack<int>st;
      int mxArea = 0;
      for(int i=0;i<=n;i++)
      {
          int currHeight = i==n ? 0 : heights[i];
          while(!st.empty() && currHeight < heights[st.top()])
          {
              int tp = st.top();
              st.pop();
              int width = st.empty() ? i : i-st.top()-1;
              int area = heights[tp]*width;
              mxArea = max(mxArea,area);
          }
          st.push(i);
      }
      return mxArea;
  }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int res = 0;
        vector<int>v(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]==1)
                v[j]+=M[i][j];
                else
                v[j] = 0;
            }
            res = max(res,histo(v,m));
        }
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends