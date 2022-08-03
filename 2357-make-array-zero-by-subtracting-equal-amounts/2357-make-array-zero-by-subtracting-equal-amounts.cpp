class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>s;
        for(auto x: nums)
        {
            if(x>0)
            {
                s.insert(x);
            }
        }
        return s.size();
    }
};
// 1 3 5 5
// 0 2 5 5
// 0 0 3 3