class Solution {
public:
    bool isMatch(string s, string p) {
        
        if(p == "*")    return true;
        int n = s.size();
        int m = p.size();
        vector< vector<bool> > dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int i = 0; i < n+1; ++i) {
            for(int j = 1; j < m+1; ++j) {
                if(i == 0) {
                    dp[i][j] = dp[i][j-1] && (p[j-1] == '*');
                }
                else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else {
                    dp[i][j] = dp[i-1][j-1] && ((s[i-1] == p[j-1]) || (p[j-1] == '?'));
                }
            }
        }
        return dp[n][m];
    }
};
