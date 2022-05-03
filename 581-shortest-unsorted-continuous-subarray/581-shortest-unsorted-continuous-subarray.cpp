class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0, end = -1;
        int mx = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(mx>nums[i])
            {
                end = i;
            }
            else
            {
                mx = nums[i];
            }
        }
        int mn = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(mn<nums[i])
            {
                start = i;
            }
            else
            {
                mn = nums[i];
            }
        }
        return end - start + 1;
    }
};