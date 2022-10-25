class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string res1 = "",res2 = "";
        for(auto x : word1) res1+=x;
        for(auto x : word2) res2+=x;
        return res1==res2;
    }
};