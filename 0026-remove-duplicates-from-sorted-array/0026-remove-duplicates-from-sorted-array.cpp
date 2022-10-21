class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=1,k=1;
        for(i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};