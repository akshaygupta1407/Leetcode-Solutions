```
class Solution {
public:
int longestConsecutive(vector<int>& nums) {
set<int>hashset;
for(int num : nums)
{
hashset.insert(num);
}
int length = 0;
for(int num : nums)
{
if(!hashset.count(num-1))
{
int currNum = num;
int currlength = 1;
while(hashset.count(currNum+1))
{
currNum++;
currlength++;
}
length = max(length,currlength);
}
}
return length;
}