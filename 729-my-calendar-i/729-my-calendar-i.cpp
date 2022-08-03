class MyCalendar {
public:
    vector<pair<int,int>>v;
    MyCalendar() {
        v.clear();
    }
    
    bool book(int start, int end) {
        if(v.empty())
        {
            v.push_back({start,end});
            return true;
        }
        sort(v.begin(),v.end());
        for(auto x : v)
        {
            if(x.first<end && x.second>start)
                return false;
        }
        v.push_back({start,end});
        return true;
    }
};
// ["MyCalendar","book","book","book","book","book","book","book","book","book","book"]
// [[],[47,50],[33,41],[39,45],[33,42],[25,32],[26,35],[19,25],[3,8],[8,13],[18,27]]
// (33 41)(47 50) 


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */