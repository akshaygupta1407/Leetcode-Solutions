class Solution {
public:
    int count = 0;
    void dfs(unordered_map<int,list<int>>&h,unordered_map<int,bool>&visited,int node)
    {
        if(visited[node])   return;
        visited[node] = true;
        count++;
        for(auto x : h[node])
        {
            if(!visited[x])
            {
                dfs(h,visited,x);
            }
        }
        return;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,list<int>>h;
        unordered_map<int,bool>visited;
        for(auto x : edges)
        {
            h[x[0]].push_back(x[1]);
            h[x[1]].push_back(x[0]);
        }
        for(auto x : restricted)
        {
            visited[x] = true;
        }
        dfs(h,visited,0);
        return count;
    }
};