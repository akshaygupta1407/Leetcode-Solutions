class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mpp;
        for(auto x : arr)
        {
            mpp[x] = 0;
        }
        vector<int>res;
        int count = 1;
        for(auto x : mpp)
        {
            mpp[x.first] = count;
            count++;
        }
        for(auto x : arr)
        {
            int c = mpp[x];
            res.push_back(c);
        }
        return res;
    }
};