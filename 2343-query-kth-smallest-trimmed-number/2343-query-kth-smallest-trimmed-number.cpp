static const auto speedup = []() {
std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        map<int,set<pair<string,int>>>m;
        int l = nums[0].length();
        vector<int>res;
        for(int i=1;i<=l;i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                string s = nums[j];
                s = s.substr(l-i);
                // cout<<s<<endl;
                m[i].insert(make_pair(s,j));
            }
            // sort(m[i].begin(),m[i].end());
        }
        // for(auto x : m)
        // {
        //     cout<<x.first<<"-->";
        //     for(auto y : x.second)
        //     {
        //         cout<<"{"<<y.first<<","<<y.second<<"},";
        //     }
        //     cout<<endl;
        // }
        for(auto z : queries)
        {
            int ans = 0;
            int a = z[0];
            // ans = m[z[1]][a-1].second;
            // res.push_back(ans);
            for(auto x : m[z[1]])
            {
                ans = x.second;
                a--;
                if(a==0)
                {
                    res.push_back(ans);
                    break;
                }    
            }
        }
        return res;
    }
};