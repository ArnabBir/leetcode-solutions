// Link: https://leetcode.com/problems/number-of-good-binary-strings/

class Solution {
    const int MOD = 1e9 + 7;

public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        long long count = 0;
        vector<int> dp(maxLength+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= maxLength; ++i) {
            if (i >= oneGroup) {
                dp[i] = (dp[i] + dp[i-oneGroup]) % MOD;
            }
            if (i >= zeroGroup) {
                dp[i] = (dp[i] + dp[i-zeroGroup]) % MOD;
            }
            if (i >= minLength) {
                count = (count + dp[i]) % MOD;
            }
        }
        return count;
    }
};