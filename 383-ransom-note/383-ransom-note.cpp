class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>mpp;
        for(auto x : magazine)
        {
            mpp[x]++;
        }
        for(int i=0;i<ransomNote.size();i++)
        {
            if(mpp[ransomNote[i]]<=0)   return false;
            mpp[ransomNote[i]]--;
        }
        return true;
    }
};