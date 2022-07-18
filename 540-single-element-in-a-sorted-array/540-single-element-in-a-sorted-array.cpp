class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        while(s<e)
        {
            int mid = (s+e)/2;
            if(mid%2==0)
            {
                if(nums[mid]!=nums[mid+1])
                {
                    e = mid;
                }
                else
                {
                    s = mid+1;
                }
            }
            else
            {
                if(nums[mid]==nums[mid+1])
                {
                    e = mid;
                }
                else
                {
                    s = mid+1;
                }
            }
        }
        return nums[s];
    }
};