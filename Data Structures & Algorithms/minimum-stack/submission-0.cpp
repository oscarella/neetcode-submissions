class MinStack {
private:
    std::vector<int> s;
public:
    // Each function should be in O(1) time

    MinStack() { // initializes the stack object
        
    }
    
    void push(int val) { // pushes val onto the stack
        s.push_back(val);
    }
    
    void pop() { // removes element on top of stack
        s.pop_back();
    }
    
    int top() { // gets top element of stack
        return s[s.size() - 1];
    }
    
    int getMin() { // retrives min element in the stack
        if (!s.size()) return -1;
        int min = s[0];
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (s[i] < min) min = s[i];
        }
        return min;
    }
};
