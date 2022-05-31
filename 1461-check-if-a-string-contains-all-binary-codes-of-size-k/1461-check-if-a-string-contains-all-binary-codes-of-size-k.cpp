class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>set;
        if(k>s.length())return false;
        for(int i=0;i<s.length()-k+1;i++)
        {
            string p = s.substr(i,k);
            set.insert(p);
        }
        return set.size()==(pow(2,k));
    }
};