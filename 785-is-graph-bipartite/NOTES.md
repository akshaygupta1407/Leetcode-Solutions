[link](https://leetcode.com/problems/is-graph-bipartite/discuss/1065709/C%2B%2B-or-DFS-or-O(n)-8ms-Beats-100-or-Explanation)
​
M1
```
// 0 -> uncoloured
// 1 - > red color
// -1 -> blue color
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
return false;
else if(color[x]==0){
color[x]= -color[node];
q.push(x);
}
}
}
}
}
return true;
}
};
```