// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
int longestPathHelper(int n, int m, vector< vector<int>> &mat, int i, int j, int dx, int dy , vector< vector<bool>> &vis) {

	if ( i < 0 || i >= n || j < 0 || j >= m ) {
		return -1;
	}
	
	if ( vis[i][j] || mat[i][j] == 0 ) {
		return -1;
	}

	if (i == dx && j == dy) {
		return 0;
	}

	vis[i][j] = true;

	int ans = -1;

	int n_ans = longestPathHelper(n, m, mat, i - 1, j, dx, dy, vis);

	if ( n_ans != -1) {
		ans = max(ans, 1 + n_ans);
	}

	int s_ans = longestPathHelper(n, m, mat, i + 1, j, dx, dy, vis);

	if ( s_ans != -1) {
		ans = max(ans, 1 + s_ans);
	}

	int e_ans = longestPathHelper(n, m, mat, i, j + 1, dx, dy, vis);

	if ( e_ans != -1) {
		ans = max(ans, 1 + e_ans);
	}

	int w_ans = longestPathHelper(n, m, mat, i, j - 1, dx, dy, vis);

	if ( w_ans != -1) {
		ans = max(ans, 1 + w_ans);
	}

	vis[i][j] = false;
	return ans;
}
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false) );

	return longestPathHelper(n, m, matrix, xs, ys, xd, yd, vis);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends