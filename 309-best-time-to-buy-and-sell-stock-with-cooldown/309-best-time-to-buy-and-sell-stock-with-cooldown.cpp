class Solution {
public:
    int helper(vector<int>& prices,int index,vector<int>&dp)
    {
        if(index>=prices.size())    return 0;
        int mx = 0;
        if(dp[index]!=-1)   return dp[index];
        for(int i=index+1;i<prices.size();i++)
        {
            mx = max(mx,prices[i]-prices[index] + helper(prices,i+2,dp));
        }
        mx = max(mx,helper(prices,index+1,dp));
        return dp[index] = mx;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(n+1,-1);
        return helper(prices,0,dp);
    }
};