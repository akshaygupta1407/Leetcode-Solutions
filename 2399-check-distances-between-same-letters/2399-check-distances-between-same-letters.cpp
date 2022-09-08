class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char,int>mpp;
        for(int i=0;i<s.length();i++)
        {
            mpp[s[i]] = abs(mpp[s[i]]-i);
        }
        for(auto x : mpp)
        {
            cout<<x.second<<endl;
            if(distance[x.first-'a']!=x.second-1) return false;
        }
        return true;
    }
};