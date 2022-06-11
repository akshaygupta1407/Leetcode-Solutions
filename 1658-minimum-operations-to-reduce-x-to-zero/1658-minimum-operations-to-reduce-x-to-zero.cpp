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
        for(i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(j<nums.size() && sum>remaining)
            {
                sum-=nums[j];
                j++;
            }
            if(sum==remaining)
            {
                len = max(len,i-j+1);
            }
        }
        if(len==0)
            return -1;
        return nums.size()-len;
    }
};