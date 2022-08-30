class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first transpose
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
        // reflect
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = tmp;
            }
        }
    }
};
/*
1 2 3
4 5 6
7 8 9
transpose
1 4 7
2 5 8
3 6 9
reflect
7 4 1
8 5 2
9 6 3
*/