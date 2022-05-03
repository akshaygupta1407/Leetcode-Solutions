[1,3,2,2,2]
index1 = 2
​
​
​
class Solution {
public:
int findUnsortedSubarray(vector<int>& nums) {
int index1 = 0, index2 = 0;
for(int i=0;i<nums.size()-1;i++)
{
if(nums[i]>nums[i+1])
{
index1 = i+1;
break;
}
}
for(int i = nums.size()-1;i>0;i--)
{
if(nums[i]<nums[i-1])
{
index2 = i + 1;
break;
}
}
if(index2>index1)
return index2 - index1 + 1;
return 0;
}
};
// 2 4 6 8 10 9 15
//  [2,6,4,8,10,9,15]
//  i = 2
//     j = 6        j - i + 1
//      2 4 6 8 10 9 15
//      i = 5   j = 6
// [1,3,2,2,2]
​