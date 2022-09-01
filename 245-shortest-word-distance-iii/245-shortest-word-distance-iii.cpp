class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string,int>mpp;
        int ans = INT_MAX;
        for(int i=0;i<wordsDict.size();i++)
        {
            if(wordsDict[i]==word1)
            {
                if(mpp.find(word2)!=mpp.end()) ans = min(ans,i-mpp[word2]);
                mpp[wordsDict[i]] = i;
            }
            else if(wordsDict[i]==word2)
            {
                if(mpp.find(word1)!=mpp.end()) ans = min(ans,i-mpp[word1]);
                mpp[wordsDict[i]] = i;
            }
        }
        return ans;
    }
};