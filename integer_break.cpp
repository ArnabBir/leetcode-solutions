vector<int> dp(60, -1);

class Solution {
        
public:
    int integerBreak(int n) {
        if(n == 1)  return 1;
        if(dp[n] != -1)     return dp[n];
        int val = 0;
        for(int i = 1; i < n; ++i) {
            val = max(val, i*max(n-i, integerBreak(n-i)));
        }
        dp[n] = val;
        return dp[n];
    }
};
