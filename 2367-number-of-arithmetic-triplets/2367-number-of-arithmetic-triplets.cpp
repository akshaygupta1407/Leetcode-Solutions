class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        map<int,int>m;
        int res = 0;
        for(auto x : nums)
        {
            res+=m[x-diff] && m[x-2*diff];
            m[x] = true;
        }
        return res;
    }
};