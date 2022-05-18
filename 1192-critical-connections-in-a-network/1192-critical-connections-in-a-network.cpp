class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<vector<int>>bridge;
    void addedge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u,vector<int>&disc,vector<int>&low,vector<int>&parent)
    {
        static int time = 0;
        disc[u] = low[u] = time;
        time+=1;
        for(int v : adj[u])
        {
            if(disc[v]==-1)
            {
                parent[v] = u;
                dfs(v,disc,low,parent);
                low[u] = min(low[u],low[v]);
                if(low[v]>disc[u])
                {
                    bridge.push_back({u,v});
                }
            }
            else if(v!=parent[u])
            {
                low[u] = min(low[u],disc[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(auto x : connections)
        {
            addedge(x[0],x[1]);
        }
        vector<int>disc(n,-1),low(n,-1),parent(n,-1);
        for(int i=0;i<n;i++)
        {
            if(disc[i]==-1)
            {
                dfs(i,disc,low,parent);
            }
        }
        return bridge;
    }
};