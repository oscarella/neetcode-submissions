class Solution {
public:
    bool isValid(string s) { // Possible brackets: '(', '{', '['
        vector<char> brackets;
        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[') brackets.push_back(c);
            else { // closing brackets
                if ((c == ')' && !brackets.empty() && brackets.back() == '(') 
                || (c == '}' && !brackets.empty() && brackets.back() == '{') 
                || (c == ']' && !brackets.empty() && brackets.back() == '[')) {
                    brackets.pop_back();
                } else {
                    return false;
                }
            }
        }
        if (brackets.empty()) return true;
        else return false;
    }
};
