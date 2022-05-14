class Solution {
public:
    unordered_map<int,list<pair<int,int>>>h;
    void addedge(int u,int v,int w)
    {
        h[u].push_back({v,w});
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto x : times)
        {
            addedge(x[0],x[1],x[2]);
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        queue<int>q;
        q.push(k);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto children : h[node])
            {
                int time = children.second;
                int neighbournode = children.first;
                int arrivaltime = dist[node] + time;
                if(dist[neighbournode]>arrivaltime)
                {
                    q.push(neighbournode);
                    dist[neighbournode] = arrivaltime;
                }
            }
        }
        int mx = 0;
        for(int i=1;i<=n;i++)
        {
            mx = max(mx,dist[i]);
            if(dist[i]==INT_MAX && i!=k)
                return -1;
        }
        return mx;
    }
};