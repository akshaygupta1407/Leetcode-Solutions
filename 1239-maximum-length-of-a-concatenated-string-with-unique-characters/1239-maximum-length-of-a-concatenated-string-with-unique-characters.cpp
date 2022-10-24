class Solution {
public:
    int len = 0;
    bool helper(string w)
    {
        unordered_set<char>st;
        for(auto x : w)
        {
            if(st.find(x)!=st.end())    return false;
            st.insert(x);
        }
        return true;
    }
    void checkLen(string str,vector<string>&arr,int i)
    {
        if(!helper(str)) return;
         if (str.size() > len) len = str.size();
        for(int x = i; x<arr.size();x++)
            checkLen(str+arr[x],arr,x+1);
    }
    int maxLength(vector<string>& arr) {
        checkLen("",arr,0);
        return len;
    }
};