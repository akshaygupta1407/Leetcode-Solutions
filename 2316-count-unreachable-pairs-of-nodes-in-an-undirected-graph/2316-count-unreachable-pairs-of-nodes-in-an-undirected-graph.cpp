class Solution {
public:
    void dfs(int node,unordered_map<int,list<int>>&h,long long &cnt,vector<int>&visited)
    {
        visited[node] = 1;
        cnt++;
        for(auto x : h[node])
        {
            if(!visited[x])
                dfs(x,h,cnt,visited);
        }
        return;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>>h;
        for(auto x : edges)
        {
            h[x[0]].push_back(x[1]);
            h[x[1]].push_back(x[0]);
        }
        long long ans = ((long long)n*(n-1))/2;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                long long count = 0;
                dfs(i,h,count,visited);
                ans-=(count*(count-1))/2;
            }
        }
        return ans;
    }
};