class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(26,0);
        for(int i=0;i<s.length();i++)
        {
            v[s[i]-'a']++;
        }
        unordered_set<int>set;
        int deletee = 0;
        for(int i=0;i<26;i++)
        {
            while(v[i] && set.find(v[i])!=set.end())
            {
                v[i]--;
                deletee++;
            }
            set.insert(v[i]);
        }
        return deletee;
    }
};
// aaabbbcc
// 3 3 2 
// 3 2 1

// ceabaacb
// 3 2 2 1
// 3 2 1 0