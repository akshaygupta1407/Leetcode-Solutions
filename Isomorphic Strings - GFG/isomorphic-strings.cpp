// { Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int n = str1.length(), m = str2.length();
        if(n!=m)    return false;
        unordered_map<char,char>mpp1,mpp2;
        for(int i=0;i<n;i++)
        {
            if(mpp1.find(str1[i])==mpp1.end())
            {
                mpp1[str1[i]] = str2[i];
            }
            else 
            {
                char ch = mpp1[str1[i]];
                if(ch!=str2[i]) return false;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(mpp2.find(str2[i])==mpp2.end())
            {
                mpp2[str2[i]] = str1[i];
            }
            else 
            {
                char ch = mpp2[str2[i]];
                if(ch!=str1[i]) return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends