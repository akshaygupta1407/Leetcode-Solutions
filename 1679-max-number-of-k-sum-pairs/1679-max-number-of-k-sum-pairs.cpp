class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            int p = k - nums[i];        // 2
            if(m.find(p)!=m.end())
            {
                m[p]--;
                if(m[p]==0)
                {
                    m.erase(p);
                }
                count++;
            }
            else
            m[nums[i]]++;
        }
        return count;
    }
};
    
// [1,2,3,4]

// m
// key value
// 1   1
// 2   0
    