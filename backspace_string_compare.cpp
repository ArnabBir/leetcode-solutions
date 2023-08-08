// Link : https://leetcode.com/problems/backspace-string-compare

class Solution {
    string get_original_word(string word) {
        string result;
        for (int i = 0; i < (int)word.size(); ++i) {
            if (word[i] == '#') {
                if (result.size() > 0) {
                    result.pop_back();
                }
            } else {
                result.push_back(word[i]);
            }
        }
        return result;
    }
public:
    bool backspaceCompare(string s, string t) {
        return get_original_word(s) == get_original_word(t);
    }
};
