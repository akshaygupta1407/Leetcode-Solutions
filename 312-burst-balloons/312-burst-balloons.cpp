class Solution {
public:
    int helper(vector<int>&arr, int i,int j,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        int ans = 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        for(int k=i+1;k<j;k++)
        {
            ans = max(ans,arr[i]*arr[k]*arr[j] + helper(arr,i,k,dp) + helper(arr,k,j,dp));
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n+2,1);
        
        for(int i=0;i<n;i++)
        {
            arr[i+1] = nums[i];
        }
        n+=2;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(arr,0,n-1,dp);
    }
};