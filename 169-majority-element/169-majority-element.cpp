class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0],count = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(count==0)
            {
                element = nums[i];
            }
            if(element==nums[i])
                count++;
            else
                count--;
        }
        return element;
    }
};