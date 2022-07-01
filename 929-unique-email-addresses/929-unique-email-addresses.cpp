class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string>s;
        for(auto x : emails)
        {
            string s1 = "",s2 = "";
            int i = 0;
            while(i<x.length() && x[i]!='@' && x[i]!='+')
            {
                if(x[i]!='.')
                s1+=x[i];
                i++;
            }
            if(x[i]=='+')
            {
                while(x[i]!='@')    i++;
            }
            i++;
            while(i<x.length())
            {
                s2+=x[i];
                i++;
            }
            // cout<<s1<<" "<<s2<<endl;
            string res = s1+'@'+s2;
            s.insert(res);
        }
        return s.size();
    }
};