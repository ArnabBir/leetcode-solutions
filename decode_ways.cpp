class Solution {
private:
    int n;
    vector<int> dp;
public:
    
    
    int numDecodingsUtil(string s, int x) {
        if(dp[x] != -1) return dp[x];
        if(x == n) {
            return 1;
        }
        dp[x] = 0;
        if(s[x] != '0') {
            dp[x] += numDecodingsUtil(s,x+1);
        }
        if(x < n-1 && s[x] == '1') {
            dp[x] += numDecodingsUtil(s,x+2);
        }
        if(x < n-1 && s[x] == '2' && s[x+1] < '7') {
            dp[x] += numDecodingsUtil(s,x+2);
        }
        return dp[x];
    }
    
    int numDecodings(string s) {
        n = s.size();
        dp.resize(n+1,-1);
        if(s[0] == '0')       return 0;
        return numDecodingsUtil(s, 0);   
    }
};
