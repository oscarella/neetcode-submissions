class Solution {
public:
    // (, [, {
    bool isValid(string s) {
        vector<char> c;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            switch (s[i]) {
                case ')':
                    if (c.size() && c[c.size() - 1] == '(') c.pop_back();
                    else return false;
                    break;
                case ']':
                    if (c.size() && c[c.size() - 1] == '[') c.pop_back();
                    else return false;
                    break;
                case '}':
                    if (c.size() && c[c.size() - 1] == '{') c.pop_back();
                    else return false;
                    break;
                default:
                    c.push_back(s[i]);
                    break;
            }
        }
        if (!c.size()) return true; // empty
        return false;
    }
};
