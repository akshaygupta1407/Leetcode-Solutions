class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return true;
        if(nums[0]==0)  return false;
        int maxreach = nums[0],steps = nums[0],jump = 1;
        for(int i=1;i<n;i++)
        {
            if(i==n-1)  return true;
            maxreach = max(maxreach,i+nums[i]);
            steps--;
            if(steps==0)
            {
                jump++;
                if(i>=maxreach) return false;
                steps = maxreach - i;
            }
        }
        return false;
    }
};