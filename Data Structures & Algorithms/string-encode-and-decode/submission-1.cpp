class Solution {
public:

    string encode(vector<string>& strs) {
        string retstr = "";
        for (auto &s: strs) {
            int n = s.size();
            retstr += to_string(n) + "#" + s;
        }
        return retstr;
    }

    vector<string> decode(string s) {
        int index = 0, n = s.size();
        vector<string> retvec;

        while (index < n) {
            string tmp = "";
            while (s[index] != '#') {
                tmp += s[index];
                ++index;
            }
            // Acquired size of substr
            int substr_len = stoi(tmp);
            tmp = "";
            ++index;
            // At start of substr
            string substr = "";
            for (int j = 0; j < substr_len; ++j) {
                substr += s[index];
                ++index;
            }
            retvec.push_back(substr);
        }

        return retvec;
    }
};
