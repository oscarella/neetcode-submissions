class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> freq(26, 0);
        vector<vector<string>> retvec;

        int index = 0;
        unordered_map<string, int> m;

        for (auto &s: strs) {
            freq = vector<int>(26, 0);
            for (auto &c: s) {
                ++freq[c - 'a'];
            }
            // turn into key
            string key = "";
            for (auto &f: freq) key += to_string(f) + ","; 
            // add to m and retvec
            if (!m.count(key)) {
                m[key] = index;
                retvec.push_back({});
                ++index;
            }
            retvec[m[key]].push_back(s);
        }

        return retvec;
    }
};
