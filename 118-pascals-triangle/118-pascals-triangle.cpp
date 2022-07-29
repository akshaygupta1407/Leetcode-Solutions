class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>triangle(numRows);
        triangle[0].push_back(1);
        if(numRows<=1)
        {
            return triangle;
        }
        triangle[1].push_back(1);
        triangle[1].push_back(1);
        if(numRows==2)
        {
            return triangle;
        }
        for(int i=2;i<numRows;i++)
        {
            triangle[i].resize(i+1);
            triangle[i][0] = 1,triangle[i][i] = 1;
            for(int j=1;j<i;j++)
            {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
        return triangle;
    }
};