class Solution {
public:
    int dp[101][101][601];
    int helper(vector<string>& strs, int m, int n,int index)
    {
        if(index>=strs.size() || (m==0 && n==0))    //m->zeroes, n->ones
        {
            return 0;
        }
        if(dp[m][n][index]>0)   return dp[m][n][index];
        int zero=0,one = 0;
        for(auto x : strs[index])
        {
            if(x=='0')zero++;
            else one++;
        }
        int consider = 0,skip = 0;
        if(m>=zero && n>=one)
        {
            consider = 1 + helper(strs,m-zero,n-one,index+1);
        }
        else
        {
            consider = 0;
        }
        skip = helper(strs,m,n,index+1);
        return dp[m][n][index] = max(skip,consider);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        return helper(strs,m,n,0);
    }
};