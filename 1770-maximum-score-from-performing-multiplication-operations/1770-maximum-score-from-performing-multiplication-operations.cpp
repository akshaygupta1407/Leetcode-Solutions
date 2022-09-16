class Solution {
public:
    int dp[1001][1001];
    int helper(vector<int>& nums, vector<int>& multipliers,int i,int j,int k)
    {
        if(k>=multipliers.size())    return 0;
        if(dp[i][k]!=INT_MIN) return dp[i][k];
        int a1 = nums[i]*multipliers[k];
        int a2 = nums[j]*multipliers[k];
        return dp[i][k] = max(a1+helper(nums,multipliers,i+1,j,k+1),a2+helper(nums,multipliers,i,j-1,k+1));
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<1001;j++)
                dp[i][j] = INT_MIN;
        }
        return helper(nums,multipliers,0,n-1,0);
    }
};