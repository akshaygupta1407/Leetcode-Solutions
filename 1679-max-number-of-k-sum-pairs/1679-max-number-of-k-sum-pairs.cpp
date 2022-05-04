class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            int p = k - nums[i];
            if(m.find(p)!=m.end() && m[p]>0)
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
    
    
    
    