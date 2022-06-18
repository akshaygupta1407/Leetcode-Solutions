class Solution {
public:
    int helper(vector<int>&nums,int n,vector<int>&dp)
    {
        if(n<0) return 0;
        if(n==0 || n==1)    return nums[n];
        if(dp[n]!=-1)   return dp[n];
        return dp[n] = nums[n] + max(helper(nums,n-2,dp),helper(nums,n-3,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];
        vector<int>dp(n,-1);
        vector<int>v1(nums.begin(),nums.end()-1);
        vector<int>v2(nums.begin()+1,nums.end());
        int op1 = max(helper(v1,v1.size()-1,dp),helper(v1,v1.size()-2,dp));
        for(int i=0;i<n;i++)
        {
            dp[i] = -1;
        }
        int op2 = max(helper(v2,v2.size()-1,dp),helper(v2,v2.size()-2,dp));
        return max(op1,op2);
    }
};