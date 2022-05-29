class Solution {
public:
    unsigned int countWordsInString(std::string const& str)
    {
        std::stringstream stream(str);
        return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
    }
    unordered_map<string,int>m1;
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        for(int i=0;i<n;i++)
        {
            int c = countWordsInString(messages[i]);
            m1[senders[i]]+=c;
        }
        string res = "";
        int mx = 0;
        for(auto x : m1)
        {
            if(x.second>mx)
            {
                mx = x.second;
                res = x.first;
            }
            else if(x.second==mx)
            {
             if(res < x.first)
                {
                    res = x.first;
                }
            }
        }
        return res;
    }
};