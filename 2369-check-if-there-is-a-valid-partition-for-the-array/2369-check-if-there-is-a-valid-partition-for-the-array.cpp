class Solution {
public:
    bool solve(vector<int>&nums,int i,vector<int>&dp)
    {
        int n = nums.size();
        if(i==n)    return true;
        bool res = false;
        if(dp[i]!=-1)   return dp[i];
        if(i+1<n && nums[i]==nums[i+1])
        {
            res = res || solve(nums,i+2,dp);
        }
        if(i+2<n && nums[i]==nums[i+1] && nums[i]==nums[i+2])
        {
            res = res || solve(nums,i+3,dp);
        }
        if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1)
        {
            res = res || solve(nums,i+3,dp);
        }
        return dp[i] = res;
    }
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};