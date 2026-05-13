#include <algorithm>
#include <vector>

const int ALPHABET = 26;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> letters(ALPHABET, 0);
        for (int i = 0, len = s.length(); i < len; i++) {
            letters[s[i] - 'a']++;
        }
        for (int i = 0, len = t.length(); i < len; i++) {
            letters[t[i] - 'a']--;
        }
        for (int i = 0; i < ALPHABET; i++) {
            if (letters[i]) return false;
        }
        return true;
    }
};
