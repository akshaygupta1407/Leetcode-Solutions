class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int mx = INT_MIN;
        for(auto x : nums)
        {
            currsum+=x;
            mx = max(mx,currsum);
            if(currsum<0)
                currsum = 0;
            
        }
        return mx;
    }
};