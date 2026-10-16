class Solution {
public:
    bool isValid(string s) {
        /*
        IDEA: STACK
        - push when left paren, pop when right paren
        - FINAL CHECK: stack must be empty
        */
        vector<char> stack;
        for (auto &c: s) {
            if (c == '(' || c == '{' || c == '[') stack.push_back(c);
            else if (c == ')') {
                if (stack.size() && stack.back() == '(') stack.pop_back();
                else return false;
            } else if (c == '}') {
                if (stack.size() && stack.back() == '{') stack.pop_back();
                else return false;
            } else if (c == ']') {
                if (stack.size() && stack.back() == '[') stack.pop_back();
                else return false;
            }
        }
        return stack.empty();
    }
};
