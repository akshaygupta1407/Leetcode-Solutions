class Solution {
public:
    bool checkIfPangram(string s) {
        int num = 0;
        for(int i=0;i<s.length();i++)
        {
            int c = s[i] - 'a';
            num = (num | (1<<c));
        }
        for(int i=0;i<26;i++)
        {
            if((num&(1<<i))==0)  return false;
        }
        return true;
    }
};