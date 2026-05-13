class MinStack { // Using (val - min) method
private:
    vector<long> s;
    long min;
public:
    MinStack(): s{}, min{0} {}
    
    void push(int val) {
        if (s.empty()) {
            min = val;
            s.push_back(0);
        } else {
            s.push_back(val - min);
            if (val < min) min = val;
        }
    }
    
    void pop() {
        if (s.back() < 0) min = min - s.back();
        s.pop_back();
    }
    
    int top() { // gives you a fake number
        if (s.back() < 0) return (int)min;
        else return (int)min + s.back();
    }
    
    int getMin() {
        return (int)min;
    }
};
