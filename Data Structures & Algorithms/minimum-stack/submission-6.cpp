class MinStack {
    stack<int> s;
    int min;
public:
    MinStack(): s{}, min{0} {}
    
    void push(int val) {
        if (s.empty()) {
            s.push(0);
            min = val;
            return;
        }
        s.push(val - min);
        min = min < val ? min : val;
    }
    
    void pop() {
        if (s.top() < 0) min -= s.top();
        s.pop();
    }
    
    int top() {
        if (s.top() <= 0) return min;
        else return min + s.top();
    }
    
    int getMin() {
        return min;
    }
};
