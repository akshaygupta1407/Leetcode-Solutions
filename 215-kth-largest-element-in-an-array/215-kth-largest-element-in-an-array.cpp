class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int ans;
        priority_queue<int>p;
        for(int i=0;i<n;i++)
        {
           p.push(nums[i]);
        }
        while(k--)
        {
           ans = p.top();
           p.pop();
        }
        return ans;
    }
};