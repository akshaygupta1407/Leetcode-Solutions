class Solution {
public:
    bool helper(vector<int>&nums,int i,int sum,vector<vector<int>>&dp)
    {
        if(sum==0)  return true;
        if(i>=nums.size() || sum<0)  return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool skip = helper(nums,i+1,sum-nums[i],dp);
        bool consider = helper(nums,i+1,sum,dp);
        return dp[i][sum] = (skip or consider);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums)
        {
            sum+=x;
        }
        if(sum%2)   return false;
        // sort(nums.begin(),nums.end());
        int tofind = sum/2;
        vector<vector<int>>dp(200+1,vector<int>(20000 + 1,-1));
        return helper(nums,0,tofind,dp);
    }
};