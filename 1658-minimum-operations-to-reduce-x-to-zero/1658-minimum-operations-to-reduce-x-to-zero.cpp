class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalsum = 0;
        for(int i=0;i<nums.size();i++)
        {
            totalsum+=nums[i];
        }
        int remaining = totalsum - x;
        if(remaining==0) return nums.size();
        int i=0,j=0;
        int sum=0,len = 0;
        for(j=0;j<nums.size();j++)
        {
            sum+=nums[j];
            while(i<nums.size() && sum>remaining)
            {
                sum-=nums[i];
                i++;
            }
            if(sum==remaining)
            {
                len = max(len,j-i+1);
            }
        }
        if(len==0)
            return -1;
        return nums.size()-len;
    }
};