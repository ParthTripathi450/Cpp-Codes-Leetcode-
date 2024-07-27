class MinStack {
private:
    stack <long long> stk;
    long long min=INT_MIN;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long value = val;
        if(stk.empty()){
            stk.push(value);
            min = value;
        }
        else{
            if(value<min){
                stk.push(2*value - min);
                min = value;
            }
            else{
                stk.push(value);
            }
        }
    }
    
    void pop() {
        if (stk.empty()) return;
        if(min > stk.top()){
            min = 2*min - stk.top();
            stk.pop();
        }
        else{
            stk.pop();
        }
    }
    
    int top() {
        if(stk.empty()) return -1;
        if(stk.top()<min) return min;
        else{
            return stk.top();
        }
    }
    
    int getMin() {
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