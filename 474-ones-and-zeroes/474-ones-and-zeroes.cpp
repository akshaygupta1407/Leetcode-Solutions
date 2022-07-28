class Solution {
public:
    int dp[101][101][601];
    int helper(vector<string>& strs, int m, int n,int idx)
    {
        if(idx>=strs.size() || (m==0 && n==0))    return 0;
        int count0=0,count1=0;
        if(dp[m][n][idx]>0) return dp[m][n][idx];
        for(auto x : strs[idx])
        {
            if(x=='0')  count0++;
            else    count1++;
        }
        int consider = (m>=count0 && n>=count1) ? 1 + helper(strs,m-count0,n-count1,idx+1) : 0;
        int skip = helper(strs,m,n,idx+1);
        return dp[m][n][idx] = max(skip,consider);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        return helper(strs,m,n,0);
    }
};