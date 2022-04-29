// 0 -> uncolored
// 1 -> red 
// -1 ->blue
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,0);
        for(int i=0;i<n;i++)
        {
           if(color[i]==0)
           {
                queue<int>q;
                q.push(i);
                color[i] = 1;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for(int x : graph[node])
                    {
                        if(color[x]==color[node])
                        {
                            return false;
                        }
                        else if(color[x]==0)
                        {
                            q.push(x);
                            color[x] = -color[node];
                        }
                    }
                }
           }
        }
        return true;
    }
};