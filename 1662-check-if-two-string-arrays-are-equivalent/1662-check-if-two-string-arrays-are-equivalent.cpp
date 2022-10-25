class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int arrayidx1=0,arrayidx2=0,idx1=0,idx2=0;
        while(arrayidx1<word1.size() && arrayidx2<word2.size())
        {
            if(word1[arrayidx1][idx1]!=word2[arrayidx2][idx2]) return false;
            idx1++;
            idx2++;
            if(idx1==word1[arrayidx1].size())
            {
                arrayidx1++;
                idx1=0;
            }
            if(idx2==word2[arrayidx2].size())
            {
                arrayidx2++;
                idx2=0;
            }
        }
        return arrayidx1==word1.size() && arrayidx2==word2.size();
    }
};