class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //using priority queue
        //using maxheap
        int n = nums.size();
        int ans;
        // if(k<=n/2)
        // {
        //     //perform maxheap and find kth element 
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
        // }
        // else
        // {
        //     //perform minheap and find n-kth element
        //     priority_queue<int,vector<int>,greater<int>>p;
        //     for(int i=0;i<n;i++)
        //     {
        //         p.push(nums[i]);
        //     }
        //     k = n-k+1;
        //     while(k--)
        //     {
        //         ans = p.top();
        //         p.pop();
        //     }
        // }
        return ans;
    }
};