class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>set;
        int i=0,j=0,n = s.length();
        int mx = 0;
        while(i<n)
        {
            if(!set.count(s[i]))
            {
                set.insert(s[i]);
                int l = set.size();
                mx = max(mx,l);
                i++;
            }
            else
            {
                if(set.count(s[j]))
                {
                    set.erase(s[j]);
                    j++;
                }
            }
        }
        return mx;
    }
};