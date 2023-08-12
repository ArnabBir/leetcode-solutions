// Link : https://leetcode.com/problems/palindrome-permutation-ii

class Solution {
    void generatePalindromesHelper(unordered_map<char, int>& um,
        vector<string>& results,
        string& result,
        char odd,
        int n) {
        
        if (result.size() == n/2) {
            string reverted = result;
            reverse(reverted.begin(), reverted.end());
            string s = result;
            if (odd != '#') {
                s += odd;
            }
            s += reverted;
            results.push_back(s);
            return;
        }
        for (auto it : um) {
            char c = it.first;
            if (um[c] == 0) {
                continue;
            }
            --um[c];
            result += c;
            generatePalindromesHelper(um, results, result, odd, n);
            result.pop_back();            
            ++um[c];
        }
    }
 
public:
     vector<string> generatePalindromes(string s) {
        unordered_map<char, int> um;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            ++um[s[i]];
        }
        bool oddFound = false;
        char odd = '#';
        for (auto it : um) {
            if (it.second%2) {
                if (oddFound) {
                    return {};
                }
                odd = it.first;
                oddFound = true;
            }
        }
        for (auto it : um) {
            um[it.first] = it.second/2;
        }
        vector<string> results;
        string result = "";
        generatePalindromesHelper(um, results, result, odd, n);
        return results;
    }
};
