class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto x : s)
        {
            switch(x)
            {
                case '(':
                case '[':
                case '{': st.push(x);
                          break;
                case ')': if(!st.empty() && st.top()=='(')
                            st.pop();
                          else
                              return false;
                            break;
                case '}': if(!st.empty() && st.top()=='{')
                            st.pop();
                          else
                              return false;
                            break;
                case ']': if(!st.empty() && st.top()=='[')
                            st.pop();
                          else
                              return false;
                            break;
                    
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};