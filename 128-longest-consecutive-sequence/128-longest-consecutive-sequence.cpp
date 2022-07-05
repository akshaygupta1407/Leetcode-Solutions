class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>set;
        for(auto num : nums)
        {
            set.insert(num);
        }
        int mx = 0;
        for(auto num : nums)
        {
            if(!set.count(num-1))
            {
                int curr = num;
                int l = 1;
                while(set.count(num+1))
                {
                    l++;
                    num++;
                }
                mx = max(mx,l);
            }
        }
        return mx;
    }    
};