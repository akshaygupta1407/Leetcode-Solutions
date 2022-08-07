class Solution {
public:
    int mx = 0,count = 0;
    bool dfs(unordered_map<int,list<int>>&h,int src,vector<int>&visited)
    {
        if(visited[src]==2)
        {
            mx = max(mx,count);
            return true;
        }
        visited[src] = 2;
        for(auto nbr : h[src])
        {
            if(visited[nbr]!=1)
            {
                bool c = dfs(h,nbr,visited);
                if(c)
                {
                    count++;
                    mx = max(mx,count);
                    return true;
                }
            }
        }
        visited[src] = 1;
        return false;
    }
    int longestCycle(vector<int>& edges) {
        unordered_map<int,list<int>>h;
        int n = edges.size();
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
            {
                h[edges[i]].push_back(i);
            }
        }
        vector<int>visited(n,0);
        for(int i=0;i<n;i++)
        {
            count=0;
            if(!visited[i])
            dfs(h,i,visited);
        }
        return mx==0 ? -1 : mx;
    }
};