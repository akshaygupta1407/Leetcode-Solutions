```
class Solution {
public:
int majorityElement(vector<int>& nums) {
int element = 0,count = 0;
for(int i=0;i<nums.size();i++)
{
if(count==0)
{
element = nums[i];
}
if(nums[i]==element)
{
count++;
}
else
{
count--;
}
}
return element;
}
};
​
/*
class Solution {
public:
int majorityElement(vector<int>& nums) {
unordered_map<int,int>m;
int maj = nums.size()/2;
for(int i=0;i<nums.size();i++)
{
m[nums[i]]++;
}
for(auto x : m)
{
if(x.second>maj)
return x.first;
}
return 0;
}
};
*/
```