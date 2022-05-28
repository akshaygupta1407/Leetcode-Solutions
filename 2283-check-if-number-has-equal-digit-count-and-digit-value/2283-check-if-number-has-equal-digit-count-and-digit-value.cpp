class Solution {
public:
    bool digitCount(string num){
        unordered_map<int,int> mp;
        for(auto c:num) mp[c-'0']++;
        for(int i=0; i<num.length(); i++){
            if((num[i]-'0')!=mp[i]) return false;
        }
        return true;
    }
};