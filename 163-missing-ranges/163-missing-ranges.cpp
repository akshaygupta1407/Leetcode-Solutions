class Solution {
public:
    string format(int l,int u)
    {
        if(l==u)    return to_string(l);
        return to_string(l) + "->" + to_string(u);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string>res;
        int prev = lower-1;
        for(int i=0;i<=nums.size();i++)
        {
            int curr = (i<nums.size())?nums[i] : upper+1;
            if(prev+1<=curr-1)  res.push_back(format(prev+1,curr-1));
            prev = curr;
        }
        return res;
    }
};