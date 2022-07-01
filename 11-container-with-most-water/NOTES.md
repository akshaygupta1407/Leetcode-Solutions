**M1. Two pointer and greedy approach**
*To get the amount of water in a container, we can find it by getting the minimum height of the container and the distance of the base of the container. So we will take the **start** and **end** pointer and get the amount of water between the bars. After calculationg it, we are greedy and will try to get more water. For this we will see which bar has minimum height, So we will try to increase the height by moving the next bar (for example: if height[s] < height[e] then we will so s++ as we want to increase the height else e--) and then calculate the water. Return the maximum water.*
```
class Solution {
public:
int maxArea(vector<int>& height) {
const int n = height.size();
int s = 0,e = n-1;
int maxWater = 0;
while(s<e)
{
int water = min(height[s],height[e])*(e-s);
maxWater = max(maxWater,water);
if(height[s]<height[e])
{
s++;
}
else
{
e--;
}
}
return maxWater;
}
};
```