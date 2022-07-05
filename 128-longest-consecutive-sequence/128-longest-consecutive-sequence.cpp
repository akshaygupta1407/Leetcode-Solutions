class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        set<int>set;
        for(auto x : nums)
            set.insert(x);
        int mx = 1, count = 1;
        int prev = INT_MIN;
        for(auto x : set)
        {
            if((long)x-prev != 1)
            {
                prev = x;
                count = 1;
            }
            else
            {
                count++;
                mx = max(mx,count);
                prev = x;
            }
        }
        return mx;
    }
};
