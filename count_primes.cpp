class Solution {
public:
    int countPrimes(int n) {
        if(n == 0)  return 0;
        if(n == 1)  return 0;
        int r = (int)sqrt(n);
        bool dp[n+1];
        memset(dp, 0, sizeof dp);
        dp[2] = false;
        for(int i = 4; i <= n; i += 2) dp[i] = true;
        for(int i = 3; i <= r; i += 2) {
            int x = i;
            while(x+i < n) {
                x += i;
                dp[x] = true;
            }
        }
        int count = 0;
        for(int i = 2; i < n; ++i) {
            count += !dp[i];
        }
        return count;
    }
};
