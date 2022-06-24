class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>m;
        int a;
        for(auto x : nums)
        {
            m[x]++;
            if(m[x]==2) a = x;
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(m[i]==0) return {a,i};
        }
        return {};
        
    }
};