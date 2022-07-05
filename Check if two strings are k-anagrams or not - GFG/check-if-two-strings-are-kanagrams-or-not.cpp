// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        // code here
        if(str1.length()!=str2.length())    return false;
        vector<int>res(26,0);
        for(int i=0;i<str1.length();i++)
        {
            res[str1[i]-'a']++;
            res[str2[i]-'a']--;
        }
        int count = 0;
        for(auto x : res)
        {
            if(x>0) count+=x;
        }
        return count<=k;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}  // } Driver Code Ends