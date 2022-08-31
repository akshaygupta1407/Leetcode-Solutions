class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        long index1=INT_MIN,index2=INT_MAX;
        long mn = INT_MAX;
        for(int i=0;i<wordsDict.size();i++)
        {
            if(wordsDict[i]==word1) index1=i;
            if(wordsDict[i]==word2) index2=i;
            mn = min(mn,abs(index1-index2));
        }
        return mn;
    }
};