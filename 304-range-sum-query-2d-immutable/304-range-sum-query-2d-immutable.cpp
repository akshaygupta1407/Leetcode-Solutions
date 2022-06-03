class NumMatrix {
public:
    vector<vector<int>>res;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        if(n==0 || m==0)
            return;
        res.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res[i+1][j+1] = res[i+1][j] + res[i][j+1] + matrix[i][j] - res[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return res[row2+1][col2+1] - res[row1][col2+1] + res[row1][col1] - res[row2+1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */