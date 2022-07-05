class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mpp;
        char ch = 'a';
        for(int i=0;i<key.length();i++)
        {
            if(key[i]!=' ')
            {
                if(mpp.find(key[i])==mpp.end())
                {
                    mpp[key[i]] = ch;
                    ch++;
                }
            }
        }
        string res = "";
        for(int i=0;i<message.length();i++)
        {
            if(message[i]==' ') res+=' ';
            else
            {
                res+=mpp[message[i]];
            }
        }
        return res;
    }
};