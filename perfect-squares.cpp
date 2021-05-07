class Solution {

private:
    int dp[10001];
    
public:
    Solution() {
        dp[1] = 1;
        memset(dp, 0, sizeof dp);
    }
    
    int numSquares(int n) {
        if(n == 0)  return 0;
        if(dp[n] != 0)  return dp[n];
        int r = (int)sqrt(n);
        int maxsq = INT_MAX;
        for(int i = r; i >= 1; --i) {
            maxsq = min(maxsq, numSquares( n - i*i) + 1);
        }
        dp[n] = maxsq;
        return dp[n];
    }
};
