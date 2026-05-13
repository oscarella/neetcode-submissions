class MinStack {
private:
    vector<pair<int,int>> v;
public:
    MinStack(): v{} {}
    
    void push(int val) {
        if (v.empty()) v.push_back({val, val});
        else {
            int minval = v.back().second;
            if (minval < val) v.push_back({val, minval});
            else v.push_back({val, val});
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};
