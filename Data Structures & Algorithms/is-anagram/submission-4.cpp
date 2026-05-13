class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charCount;
        for (char &c: s) {
            if (charCount.count(c)) ++charCount[c];
            else charCount[c] = 0;
        }
        for (char &c: t) {
            if (charCount.count(c)) --charCount[c];
            else return false;
        }
        for (auto& [c, freq]: charCount) if(!freq) return false;
        return true;
    }
};
