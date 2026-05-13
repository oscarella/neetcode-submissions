class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alphabet(26, 0);
        for (char c: s) alphabet[c - 'a']++;
        for (char c: t) alphabet[c - 'a']--;
        for (auto i: alphabet) {
            if (i != 0) return false;
        }
        return true;
    }
};
