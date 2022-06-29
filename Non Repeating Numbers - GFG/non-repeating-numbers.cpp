// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xr = 0;
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            xr = xr ^ nums[i];
        }
        int mask = 1;
        while((mask&xr)==0)
        {
            mask = mask<<1;
        }
        int a = 0,b = 0;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&mask)==0) a^=nums[i];
            else b^=nums[i];
        }
        res.push_back(a);
        res.push_back(b);
        if(a>b)
        swap(res[0],res[1]);
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends