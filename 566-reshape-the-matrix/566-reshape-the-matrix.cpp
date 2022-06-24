class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>>res(r,vector<int>(c));
        int m = mat.size(), n=mat[0].size();
        int total = m*n;
        if(total!=r*c)
        {
            return mat;
        }
        for(int i=0;i<total;i++)
        {
            res[i/c][i%c] = mat[i/n][i%n];
        }
        return res;
    }
};