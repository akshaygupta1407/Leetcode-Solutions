class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2) return {};
        vector<int>res;
        map<int,int>mpp;
        sort(changed.begin(),changed.end());
        for(auto x : changed)
        {
            mpp[x]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mpp[changed[i]*2]>0 && mpp[changed[i]]>0 && changed[i]!=0)
            {
                res.push_back(changed[i]);
                mpp[changed[i]*2]--;
                mpp[changed[i]]--;
                
            }
            else if(changed[i]==0 && mpp[0]>=2)
            {
                res.push_back(changed[i]);
                mpp[0]-=2;
            }
        }
        if(res.size()!=n/2)
        {
            res.clear();
            return res;
        }
        return res;
    }
};