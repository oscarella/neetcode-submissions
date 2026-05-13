class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> retvec;
        unordered_map<string,int> m;
        int index = 0;

        for (auto &s: strs) {
            vector<int> charFreq(26, 0);
            for (auto &c: s) {
                ++charFreq[c - 'a'];
            }
            // Finished computation of charFreq
            string key = "";
            for (int &i: charFreq) key += to_string(i) + ",";
            // Check if belongs to m
            if (m.count(key)) {
                retvec[m[key]].push_back(s);
            } else {
                m[key] = index;
                ++index;
                retvec.push_back({});
                retvec[m[key]].push_back(s);
            }
        }
        return retvec;
    }
};
