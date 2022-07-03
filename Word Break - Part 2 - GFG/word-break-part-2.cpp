// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string>res;
    void findHelper(int index,unordered_set<string>set,string curr,string s)
    {
        if(index==s.length())
        {
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        string str = "";
        for(int i=index;i<s.length();i++)
        {
            str.push_back(s[i]);
            if(set.count(str))
            {
                findHelper(i+1,set,curr + str + " " ,s);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        unordered_set<string>set;
        for(auto x : dict)
        {
            set.insert(x);
        }
        string curr = "";
        findHelper(0,set,curr,s);
        return res;   
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends