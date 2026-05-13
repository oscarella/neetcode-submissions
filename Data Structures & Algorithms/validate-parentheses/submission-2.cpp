class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> closeToOpen{
            {')','('},
            {'}','{'},
            {']','['}
        };
        vector<char> cont;
        for (char c : s) {
            if (closeToOpen.count(c)) {
                if (!cont.empty() && cont.back() == closeToOpen[c]) cont.pop_back();
                else return false;
            } else {
                cont.push_back(c);
            }
        }
        return cont.empty();
    }
};
