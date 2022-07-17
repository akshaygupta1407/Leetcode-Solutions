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
        int ans = -1;
        int mx1 = 0,mx2 = 0;
        for(auto x : mpp)
        {
            mx1=0,mx2=0;
            cout<<x.first<<"->";
            for(auto y : x.second)
            {
                cout<<y<<",";
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
            cout<<endl;
            cout<<mx1<<" "<<mx2<<endl;
            if(mx1!=0 && mx2!=0)
            {
                ans = max(ans,mx1+mx2);
            }
        }
        return ans;
    }
};