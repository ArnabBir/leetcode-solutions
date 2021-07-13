class MinStack {
private:
    stack<long> s;
    long min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push(val);
            min = val;
        }
        else if(val >= min) {
            s.push(val);
        }
        else {
            s.push(2*(long)val-(long)min);
            min = val;
        }
    }
    
    void pop() {
        if(s.empty())       return;
        long top = s.top();
        if(top < min) {
            min = 2*min-top;   
        }
        s.pop();
    }
    
    int top() {
        if(s.empty())       return -1;
        long top = s.top();
        if(top < min) {
            return min; 
        }
        return top;
    }
    
    int getMin() {
        if(s.empty())   return -1;
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
