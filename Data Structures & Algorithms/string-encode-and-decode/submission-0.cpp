class Solution {
    vector<int> iLen;
public:

    string encode(vector<string>& strs) {
        string retstr = "";
        for (auto &s: strs) {
            int n = s.size();
            iLen.push_back(n);
            retstr += s;
        }
        return retstr;
    }

    vector<string> decode(string s) {
        vector<string> retvec;
        int sIndex = 0;
        for (int i = 0, n = iLen.size(); i < n; ++i) {
            string subStr = "";
            for (int j = 0; j < iLen[i]; ++j) {
                subStr += s[sIndex++];
            }
            retvec.push_back(subStr);
        }
        return retvec;
    }
};
