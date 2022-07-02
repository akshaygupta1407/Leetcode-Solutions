// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int helper(unordered_map<int,list<int>>&h,vector<bool>&visited,int s,int d)
    {
        if(s==d)
            return 1;
        visited[s] = true;
        int ans = 0;
        for(auto x : h[s])
        {
            if(!visited[x])
            {
                ans+=helper(h,visited,x,d);
            }
        }
        visited[s] = false;
        return ans;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    unordered_map<int,list<int>>h;
	    for(auto x : edges)
	    {
	        h[x[0]].push_back(x[1]);
	    }
	    vector<bool>visited(n,0);
	    return helper(h,visited,s,d);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends