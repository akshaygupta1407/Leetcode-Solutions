// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string extendfrommiddle(string s,int i,int j)
    {
        while(i>=0 && j<s.length() && s[i]==s[j])
        {
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalin (string S) {
        // code here
        string res = "";
        int n = S.length();
        for(int i=0;i<n;i++)
        {
            string s1 = extendfrommiddle(S,i,i);
            string s2 = extendfrommiddle(S,i,i+1);
            if(s1.length() > res.length())
            {
                res = s1;
            }
            if(s2.length() > res.length())
            {
                res = s2;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends