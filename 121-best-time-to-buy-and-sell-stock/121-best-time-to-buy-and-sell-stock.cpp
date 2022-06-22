class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = INT_MAX, mxprofit = 0;
        for(int i=0;i<prices.size();i++)
        {
            curr = min(curr,prices[i]);
            mxprofit = max(mxprofit,prices[i]-curr);
        }
        return mxprofit;
    }
};