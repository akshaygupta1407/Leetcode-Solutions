```
class Solution {
public:
int totalFruit(vector<int>& fruits) {
int mx = 0;
int currmax = 0;
int lastfruit = -1,secondlastfruit = -1;
int lastfruitcount = 0;
for(auto f : fruits)
{
if(f==lastfruit || f==secondlastfruit)
currmax++;
else
{
currmax = lastfruitcount+1;
}
if(f==lastfruit)
lastfruitcount++;
else
lastfruitcount=1;
if(f!=lastfruit)
{
secondlastfruit = lastfruit;
lastfruit = f;
}
mx = max(mx,currmax);
}
return mx;
}
};
​
/*
Input
3 3 3 1 2 1 1 2 3 3 4
​
o/p 5
*/
```