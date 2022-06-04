class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return n;
        sort(nums.begin(),nums.end());
        int count=1,mx = 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1] == 1)
            {
                count++;
            }
            else if(nums[i]==nums[i-1])
                continue;
            else
            {
                mx = max(mx,count);
                count = 1;
            }
        }
        mx = max(mx,count);
        return mx;
    }
};