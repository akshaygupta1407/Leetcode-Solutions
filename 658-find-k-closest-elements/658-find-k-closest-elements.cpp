class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        map<int,vector<int>>mpp;
        vector<int>res;
        for(int i=0;i<arr.size();i++)
        {
            int z = abs(arr[i]-x);
            mpp[z].push_back(arr[i]);
        }
        bool flag = false;
        for(auto z : mpp)
        {
            sort(z.second.begin(),z.second.end());
            for(auto y : z.second)
            {
                res.push_back(y);
                k--;
                if(k==0)
                    break;
            }
            if(k==0)    break;
        }
        sort(res.begin(),res.end());
        return res;
    }
};