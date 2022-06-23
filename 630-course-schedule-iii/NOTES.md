**Top Down Dp - TLE**
```
class Solution {
public:
static bool cmp(const vector<int>&a,const vector<int>&b)
{
return a[1] <= b[1];
}
int schedule(vector<vector<int>>& courses,int index,int duration,int size,vector<vector<int>>&dp)
{
if(index>=size) return 0;
if(dp[index][duration]!=-1) return dp[index][duration];
int d = courses[index][0];
int ld = courses[index][1];
int consider = 0,skip= 0;
if(duration + d <= ld)
{
consider = 1+schedule(courses,index+1,duration+d,size,dp);
}
skip = schedule(courses,index+1,duration,size,dp);
return dp[index][duration] = max(consider,skip);
}
int scheduleCourse(vector<vector<int>>& courses) {
if(courses.size() ==0) return 0;
sort(courses.begin(),courses.end(),cmp);
int n = courses.size();
vector<vector<int>>dp(n+1,vector<int>(courses[n-1][1]+1,-1));
return schedule(courses,0,0,n,dp);+1
}
};
```
**Using Priority Queue**
​