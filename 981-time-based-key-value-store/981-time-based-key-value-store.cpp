class TimeMap {
public:
    unordered_map<string, map<int, string>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it = mpp[key].upper_bound(timestamp);
        return it==mpp[key].begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */