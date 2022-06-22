```
class Solution {
public:
int maxProfit(vector<int>& prices) {
int mxprofit = 0,curr= INT_MAX;
for(int i=0;i<prices.size();i++)
{
curr = min(curr,prices[i]);
mxprofit = max(mxprofit,prices[i]-curr);
}
return mxprofit;
}
};
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
```