// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char,int>m;
        int i=0,j=0,mx=INT_MIN;
        while(j<s.length())
        {
            if(m.size()<=k)
            {
                if(m.size()==k && m.find(s[j])==m.end())
                {
                    m[s[i]]--;
                    if(m[s[i]]==0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                else
                {
                    m[s[j]]++;
                    mx = max(mx,j-i+1);
                    j++;
                }
            }
            else
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                {
                    m.erase(s[i]);
                }
                i++;
                
            }
        }
        if(m.size()<k)  return -1;
        return mx==INT_MIN ? -1 : mx;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends