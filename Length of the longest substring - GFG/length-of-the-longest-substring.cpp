// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        vector<int>set(30,-1);
        int l = S.length(), i = 0 , j = 0, mx=0;
        while(j<l)
        {
            if(set[S[j]-'a']!=-1)
            {
                if(set[S[j]-'a']>=i)
                {
                    i = set[S[j]-'a']+1;
                }
            }
            set[S[j]-'a'] = j;
            mx = max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends