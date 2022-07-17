class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,list<int>>mpp;
        for(auto x : nums)
        {
            int a = x;
            int sum = 0;
            while(a)
            {
                sum += a%10;
                a/=10;
            }
            mpp[sum].push_back(x);
        }
        int ans = -1, mx1 = 0,mx2 = 0;
        for(auto x : mpp)
        {
            mx1=0,mx2=0;
            for(auto y : x.second)
            {
                if(mx1<y)
                {
                    mx2 = mx1;
                    mx1 = y;
                }
                else if(mx2<y && mx2<=mx1)
                {
                    mx2 = y;
                }
            }
            if(mx1!=0 && mx2!=0)
            {
                ans = max(ans,mx1+mx2);
            }
        }
        return ans;
    }
};