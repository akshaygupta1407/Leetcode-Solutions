class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int n = s1.size();
        while(n>1)
        {
            int x = s1.top();
            s1.pop();
            s2.push(x);
            n--;
        }
        int y = s1.top();
        s1.pop();
        n = s2.size();
        while(n)
        {
            int x = s2.top();
            s2.pop();
            s1.push(x);
            n--;
        }
        return y;
    }
    int peek() {
        int n = s1.size();
        while(n>1)
        {
            int x = s1.top();
            s1.pop();
            s2.push(x);
            n--;
        }
        int y = s1.top();
        n = s2.size();
        while(n)
        {
            int x = s2.top();
            s2.pop();
            s1.push(x);
            n--;
        }
        return y;
    }
    bool empty() {
        return s1.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 stack
 push pop
 top()
 
 front()
 */