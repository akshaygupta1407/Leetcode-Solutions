class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>m;
        int ans = 0;
        for(auto x : jewels)
        {
            m[x]++;
        }
        for(auto x : stones)
        {
            if(m[x])    ans++;
        }
        return ans;
    }
};