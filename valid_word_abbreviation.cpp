// Link : https://leetcode.com/problems/valid-word-abbreviation/

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size();
        int m = abbr.size();
        vector<pair<char,int> > sp;
        for (int i = 0; i < m; ++i) {
            string numstr;
            while (abbr[i] >= '0' && abbr[i] <= '9') {
                numstr += (abbr[i++]);
            }
            if (numstr.size() > 0) {
                if(numstr[0] == '0') {
                    return false;
                }
                sp.push_back({'*', stoi(numstr)});
                --i;
            } else if (sp.size() == 0) {
                sp.push_back({abbr[i], 1});
            } else {
                pair<char, int> back = sp.back();
                if (back.first == abbr[i]) {
                    sp.pop_back();
                    sp.push_back({abbr[i], back.second + 1});
                } else {
                    sp.push_back({abbr[i], 1});
                }
            }
        }
        int j = 0, i = 0;
        for (i = 0; i < sp.size(); ++i) {
            pair<char,int> p = sp[i];
            for (int k = 0; k < p.second; ++k) {
                if (j > n-1 || (word[j] != p.first && p.first != '*')) {
                    return false;
                }
                ++j;
            }
        }
        return j == n;
    }
};
