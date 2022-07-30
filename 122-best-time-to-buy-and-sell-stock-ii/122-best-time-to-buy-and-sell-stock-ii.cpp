class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0],sell = prices[0],profit = 0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i] <= buy || sell>=prices[i])
            {
                profit+=sell-buy;
                buy = prices[i];
                sell = prices[i];
            }
            else if(sell < prices[i])
            {
                sell = max(sell,prices[i]);
            }
        }
        profit+=sell-buy;
        return profit;
    }
};