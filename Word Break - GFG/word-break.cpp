// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    vector<string>res;
    void helper(int index, string A, unordered_set<string>set,string curr)
    {
        if(index==A.length())
        {
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        string str = "";
        for(int i = index; i<A.length(); i++)
        {
            str.push_back(A[i]);
            if(set.count(str))
            {
                helper(i+1,A,set,curr+str+" ");
            }
        }
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string>set;
        for(auto x : B)
        {
            set.insert(x);
        }
        string curr = "";
        helper(0,A,set,curr);
        return res.empty() ? 0 : 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends