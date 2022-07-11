// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool cycle(unordered_map<int,list<int>>&h,vector<int>&visited,int src)
    {
        if(visited[src]==2) return true;
        visited[src] = 2;
        for(auto x : h[src])
        {
            if(visited[x]!=1)
            {
                if(cycle(h,visited,x))  return true;
            }
        }
        visited[src] = 1;
        return false;
    }
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    unordered_map<int,list<int>>h;
	    vector<int>visited(n,0);
	    for(auto x : prerequisites)
	    {
	        int u = x.first,v = x.second;
	        h[u].push_back(v);
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(visited[i]==0)
	        {
	            if(cycle(h,visited,i))  return false;
	        }
	    }
	    return true;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends