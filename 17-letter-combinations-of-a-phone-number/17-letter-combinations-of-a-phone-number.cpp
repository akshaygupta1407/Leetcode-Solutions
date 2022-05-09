class Solution {
public:
    vector<vector<char>> keypad =
    {
        {}, {},        // 0 and 1 digit don't have any characters associated
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's'},
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z'}
    };
    void backtrack(vector<string>&arr,vector<int>&input,string res,int index)
    {
        //base case
        if(index==-1)
        {
            arr.push_back(res);
            return;    
        }
        int digit = input[index];
        int len = keypad[digit].size();
        for(int i=0;i<len;i++)
        {
            backtrack(arr,input,keypad[digit][i] + res,index - 1);
        }   
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits=="")
        {
            return {};
        }
        vector<string>arr;
        vector<int>input;
        for(int i=0;i<digits.length();i++)
        {
            int d = digits[i] - '0';
            input.push_back(d);
        }
        backtrack(arr,input,"",digits.length()-1);
        return arr;
    }
};