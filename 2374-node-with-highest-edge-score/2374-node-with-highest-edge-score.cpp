class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        map<long long,long long>adj;
        int mx = 0;
        int ans;
        for(int i=0;i<n;i++)
        {
            adj[edges[i]]+=i;
        }
        for(auto x : adj)
        {
            if(mx<x.second)
            {
                mx = x.second;
                ans = x.first;
            }
        }
        return ans;
    }
};