class Solution {
public:
    string smallestNumber(string pattern) {
        string res,stack;
        for(int i=0;i<=pattern.length();i++)
        {
            stack.push_back('1'+i);
            if(pattern[i]=='I' || i==pattern.length())
            {
                while(!stack.empty())
                {
                    res.push_back(stack.back());
                    stack.pop_back();
                }
            }
        }
        return res;
    }
};
/*
I means increasing
D means decreasing
string size = n
output must be number of size n+1
3 -1 1 -3
*/