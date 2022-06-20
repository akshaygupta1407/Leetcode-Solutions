class Solution {
public:
    int kadane(vector<int>& nums)
    {
        int mx = INT_MIN,sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            mx = max(mx,sum);
            if(sum<0)   sum = 0;
        }
        return mx;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int withoutWrapping = kadane(nums);
        if(withoutWrapping < 0) return withoutWrapping;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            nums[i] = -nums[i];
        }
        int x = kadane(nums);
        int wrapping = x < 0 ? sum : sum+x;
        return max(wrapping,withoutWrapping);
    }
};