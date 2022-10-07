class MyCalendarThree {
public:
    map<int,int>mpp;
    int mx = 0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int cnt=0;
        mpp[start]++;
        mpp[end]--;
        for(auto it = mpp.begin(); it!=mpp.end();it++)
        {
            cnt+=it->second;
            mx = max(mx,cnt);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */