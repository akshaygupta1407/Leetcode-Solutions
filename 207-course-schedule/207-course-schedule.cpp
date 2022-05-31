class Solution {
public:
    /*
    0->unvisited
    1-> processed
    2->processing
    */
    bool cycle(unordered_map<int,list<int>>&h,vector<int>&visited,int src)
    {
        if(visited[src]==2)
            return true;
        visited[src] = 2;
        for(auto nbr : h[src])
        {
            if(visited[nbr]!=1)
            {
                if(cycle(h,visited,nbr))
                    return true;
            }
        }
        visited[src] = 1;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>h;
        vector<int>visited(numCourses,0);
        for(auto x : prerequisites)
        {
            int u = x[0],v = x[1];
            h[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++)
        {
                if(visited[i]==0)
                {
                    if(cycle(h,visited,i))
                        return false;
                }
        }
        return true;
    }
};