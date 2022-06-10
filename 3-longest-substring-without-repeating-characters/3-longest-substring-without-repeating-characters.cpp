class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        unordered_set<char>set;
        int mx = 0;
        while(i<s.length())
        {
            if(set.find(s[i])==set.end())
            {
                set.insert(s[i]);
                i++;
                int l = set.size();
                mx = max(mx,l); 
            }
            else
            {
                set.erase(set.find(s[j]));
                j++;
            }
        }
        return mx;
    }
};