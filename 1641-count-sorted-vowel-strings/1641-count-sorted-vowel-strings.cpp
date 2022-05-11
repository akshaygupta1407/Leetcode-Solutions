class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>>res(6,vector<int>(n,0));
        res[0][0] = res[1][0] = res[2][0] = res[3][0] = res[4][0] = 1;
        res[5][0] = 5;
        if(n==1)
        {
            return res[5][n-1];
        }
        for(int j=1;j<n;j++)
        {
            int sum = 0;
            for(int i=0;i<5;i++)
            {
                if(i==0)
                {
                    res[i][j] = res[5][j-1];
                    sum+=res[i][j];   
                }
                else
                {
                    res[i][j] = res[i-1][j] - res[i-1][j-1];
                    sum+=res[i][j]; 
                }
            }
            res[5][j] = sum;
        }
        return res[5][n-1];
    }
};