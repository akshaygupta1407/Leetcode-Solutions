class Solution {
public:
    unordered_map<int,int>m;
    int coin(vector<int>& coins,int amount)
    {
        if(amount==0)
            return 0;
        if(amount<0)    return -1;
        if(m[amount])   return m[amount];
        int mn = INT_MAX;
        for(auto c : coins)
        {
            int res = coin(coins,amount-c);
            if(res>=0 && res<mn)
            {
                mn = res+1;
            }
        }
        return m[amount] = mn==INT_MAX ? -1 : mn;
    }
    int coinChange(vector<int>& coins, int amount) {
        return coin(coins,amount);
    }
};