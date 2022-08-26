class Logger {
public:
    map<string,int>mpp;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mpp.find(message)==mpp.end())
        {
            mpp[message] = timestamp+10;
            return true;
        }
        if(mpp[message]<=timestamp)
        {
            mpp[message] = timestamp+10;
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */