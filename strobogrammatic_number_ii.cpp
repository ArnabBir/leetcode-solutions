// Link : https://leetcode.com/problems/strobogrammatic-number-ii

class Solution {
    void findStrobogrammaticHelper(unordered_map<char, char>& mir,
                            vector<string>& results,
                            string& curr, int n) {
        cout<<curr<<endl;
        if (curr.size() == n/2) {
            string suffix;
            for (char c : curr) {
                suffix = mir[c] + suffix;
            }
            if (n%2) {
                for (auto it : mir) {
                    if (it.first == '6' || it.first == '9') {
                        continue;
                    }
                    results.push_back(curr + it.first + suffix);
                }
            } else {
                results.push_back(curr + suffix);
            }
            return;
        }
        for (auto it : mir) {
            if (curr.size() == 0 && it.first == '0') {
                continue;
            }
            curr += it.first;
            findStrobogrammaticHelper(mir, results, curr, n);
            curr.pop_back();
        }
    }
 
public:
    vector<string> findStrobogrammatic(int n) {
        unordered_map<char, char> mir;
        mir['0'] = '0';
        mir['1'] = '1';
        mir['6'] = '9';
        mir['8'] = '8';
        mir['9'] = '6';
        vector<string> results;
        string curr;
        findStrobogrammaticHelper(mir, results, curr, n);
        return results;
    }
};