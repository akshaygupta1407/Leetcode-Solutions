class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int m = n-1;
        while(m && i<n)
        {
            if(i<n-1 && nums[i]==nums[i+1])
            {
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
                m--;
            }
            i++;
        }
        stable_partition(nums.begin(),nums.end(),[](int n) { return n != 0; });
        return nums;
    }
};