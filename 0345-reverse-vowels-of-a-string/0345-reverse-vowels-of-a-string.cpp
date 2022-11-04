class Solution {
public:
    bool vowel(char ch)
    {
        ch = tolower(ch);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
    string reverseVowels(string s) {
        string res = "";
        for(auto x : s)
        {
            if(vowel(x)) res+=x;
        }
        reverse(res.begin(),res.end());
        int j = 0;
        for(int i=0;i<s.length();i++)
        {
            if(vowel(s[i])) s[i] = res[j++];
        }
        return s;
    }
};