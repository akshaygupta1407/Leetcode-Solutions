class Solution {
public:
    int solve(vector<int>&nums,int currsum,int target,vector<int>&dp)
    {
        if(currsum==target) return 1;
        if(currsum>target)  return 0;
        if(dp[currsum]!=-1)  return dp[currsum];
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(currsum<=target)
            ans+=solve(nums,currsum+nums[i],target,dp);
        }
        return dp[currsum] = ans;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return solve(nums,0,target,dp);
    }
};