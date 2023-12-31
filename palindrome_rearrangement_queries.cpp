// Link : https://leetcode.com/problems/palindrome-rearrangement-queries/

class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<bool> ans;
        string bck = s;
        string rs = s;
        reverse(rs.begin(), rs.end());
        if (s == rs) {
            return vector<bool> (queries.size(), true);
        }
        unordered_set<int> diff;
        unordered_set<char> diffchars;
        for (int i = 0; i < n/2; ++i) {
            if (s[i] != s[n-1-i]) {
                diff.insert(i);
                diffchars.insert(s[i]);
                diffchars.insert(s[n-1-i]);
            }
        }
        unordered_set<int> diff2 = diff;
        for (int i = 0; i < n/2; ++i) {
            if (diffchars.find(s[i]) == diffchars.end()) {
                    continue;
            }
            diff2.insert(i);
        }
        for (int i = 0; i < n/2; ++i) {
            if (diffchars.find(s[n-1-i]) == diffchars.end()) {
                    continue;
            }
            diff2.insert(i);
        }
        for (vector<int> query : queries) {
            int a = query[0];
            int b = query[1];
            int c = query[2];
            int d = query[3];
            unordered_map<char, int> s1, s2;
            unordered_map<char, int> d1, d2;
            unordered_set<char> cs;
            bool finalans = true;
            for (int x: diff) {
                if (!(x >= a && x <= b)
                     && !(x >= (n-1-d) && x <= (n-1-c))) {
                    finalans = false;
                    break;
                }
            }
            if (!finalans) {
                ans.push_back(false);
                continue;
            }
            for (int x: diff2) {
                if (x >= a && x <= b && x >= (n-1-d) && x <= (n-1-c)) {
                    ++s1[s[x]];
                    ++s2[s[n-1-x]];
                } else if (x >= a && x <= b) {
                    ++d1[s[n-1-x]];
                    ++s1[s[x]];
                } else if (x >= (n-1-d) && x <= (n-1-c)) {
                    ++d2[s[x]];
                    ++s2[s[n-1-x]];
                }
                cs.insert(s[n-1-x]);
                cs.insert(s[x]);
            }
            for (char x : cs) {
                if (s1[x] < d1[x] || s2[x] < d2[x] || s1[x] -d1[x] != s2[x] - d2[x]) {
                    finalans = false;
                    break;
                }
            }
            ans.push_back(finalans);
        }
        return ans;
    }
};
