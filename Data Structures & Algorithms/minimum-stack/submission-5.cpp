class MinStack {
    stack<int> s;
    stack<int> min;
public:
    MinStack(): s{}, min{} {}
    
    void push(int val) {
        s.push(val);
        if (min.empty()) {
            min.push(val);
        } else {
            if (val < min.top()) min.push(val);
            else min.push(min.top());
        }
    }
    
    void pop() {
        s.pop();
        min.pop();
    }
    
    int top() {
        if (s.empty()) throw;
        return s.top();
    }
    
    int getMin() {
        if (min.empty()) throw;
        return min.top();
    }
};
