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
        // vector<bool>visited(n+1,false);
        // unordered_map<int,int>dist;
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        int ans = 0;
        int start = k;
        queue<int>q;
        // visited[start] = true;
        q.push(start);
        dist[start] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            // if(!visited[node])
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
                // visited[node] = true;
                // if(true)
                // {
                    // // visited[children.first] = true;
                    // q.push(children.first);
                    // dist[children.first] = dist[node] + children.second;
               // }
            }
            // visited[node] = true;
        }
        int mx = 0;
        for(int i=1;i<=n;i++)
        {
            mx = max(mx,dist[i]);
            if(dist[i]==INT_MAX && i!=k)
                return -1;
            cout<<i<<" "<<dist[i]<<endl;
        }
        return mx;
    }
};
// 1
// 2-> 1,3
// 3-> 4