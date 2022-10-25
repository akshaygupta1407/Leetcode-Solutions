class Solution {
public:
    long long f(vector<int>& nums, vector<int>& cost, int x)
    {
        long long res = 0;
        for(int i=0;i<nums.size();i++)
        {
            res+=1L*cost[i]*(abs(nums[i]-x));
        }
        return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l = 1, r = 1000000;
        long long res = f(nums,cost,1);
        while(l<r)
        {
            long long x = (l+r)/2;
            long long y1 = f(nums,cost,x), y2 = f(nums,cost,x+1);
            res = min(y1,y2);
            if(y1<y2)
            {
                r = x;
            }
            else
            {
                l = x+1;
            }
        }
        return res;
    }
};