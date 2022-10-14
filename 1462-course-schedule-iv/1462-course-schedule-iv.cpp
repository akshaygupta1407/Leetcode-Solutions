class Solution {
public:
    void Floyd(int n,vector<vector<int>>&m)
    {
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    m[i][j] = m[i][j] or (m[i][k] and m[k][j]);
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n,vector<int>(n));
        for(auto x: prerequisites)
        {
            adj[x[0]][x[1]] = 1;
        }
        Floyd(n,adj);
        vector<bool>ans;
        for(auto x : queries)
        {
            ans.push_back(adj[x[0]][x[1]]);
        }
        return ans;
    }
};