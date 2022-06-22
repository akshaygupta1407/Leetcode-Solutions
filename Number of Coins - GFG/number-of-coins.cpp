// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	unordered_map<int,int>m;
    int coin(int coins[],int amount,int M)
    {
        if(amount==0)
            return 0;
        if(amount<0)    return -1;
        if(m[amount])   return m[amount];
        int mn = INT_MAX;
        for(int i=0;i<M;i++)
        {
            int c = coins[i];
            int res = coin(coins,amount-c,M);
            if(res>=0 && res<mn)
            {
                mn = res+1;
            }
        }
        return m[amount] = mn==INT_MAX ? -1 : mn;
    }
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    return coin(coins,V,M);
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends