https://leetcode.com/problems/palindrome-permutation

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> um;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            ++um[s[i]];
        }
        bool oddFound = false;
        for (auto it : um) {
            if (it.second%2) {
                if (oddFound) {
                    return false;
                }
                oddFound = true;
            }
        }
        return true;
    }
};
