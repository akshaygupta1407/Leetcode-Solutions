class Solution {
public:
int findUnsortedSubarray(vector<int>& nums) {
int start = 0, end = -1;
int mn = nums[0];
for(int i=1;i<nums.size();i++)
{
if(mn>nums[i])
{
end = i;
}
else
{
mn = nums[i];
}
}
int mx = nums[nums.size()-1];
for(int i=nums.size()-2;i>=0;i--)
{
if(mx<nums[i])
{
start = i;
}
else
{
mx = nums[i];
}
}
return end - start + 1;
}
};