```
class Solution {
public:
void backtrack(vector<int>& nums, set<vector<int>>&s, vector<bool>&visited,vector<int>&sub)
{
if(sub.size()==nums.size())
{
s.insert(sub);
}
for(int i=0;i<nums.size();i++)
{
if(!visited[i])
{
sub.push_back(nums[i]);
visited[i] = true;
backtrack(nums,s,visited,sub);
visited[i] = false;
sub.pop_back();
}
}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
vector<vector<int>>res;
set<vector<int>>s;
vector<bool>v(nums.size(),false);
vector<int>sub;
backtrack(nums,s,v,sub);
for(auto x : s)
{
res.push_back(x);
}
return res;
}
};
```