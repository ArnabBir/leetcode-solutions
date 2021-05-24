class Solution {
public:
    int balancedStringSplit(string s) {
        int rc = 0, lc = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'R') ++rc;
            if(s[i] == 'L') ++lc;
            if(lc == rc) {
                ++ans;
                lc = rc = 0;
            }
        }
        return ans;
    }
};
