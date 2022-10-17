class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>count(26,0);
        for(auto x : sentence)
        {
            count[x-'a']++;
        }
        for(auto x : count)
        {
            if(x==0)    return false;
        }
        return true;
    }
};