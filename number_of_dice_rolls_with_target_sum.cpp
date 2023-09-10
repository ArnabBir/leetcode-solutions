// Link : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

/*
1           2            3            4           5 6
1 2 3 4 5 6 1 2 3 4 5 6  1 2 3 4 5 6  1 2 3 4 5 6

*/
class Solution {
    const int MOD = 1000000007; 
private:
    long countBackTracking(vector<vector<long>>& dp, int curr, int n, int k, int sum, int target) {
        if (curr > n || sum > target) {
            return 0;
        }
        if (curr == n) {
            if (sum == target) {
                return 1;
            }
            return 0;
        }
        if (dp[curr][sum] != -1) {
            return dp[curr][sum] % MOD;
        }
        dp[curr][sum] = 0;
        for (int i = 1; i <= k; ++i) {
            dp[curr][sum] = (dp[curr][sum] + countBackTracking(dp, curr+1, n, k, sum + i, target)) % MOD;
        }
        return dp[curr][sum];
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long>> dp(n+1, vector<long>(target+1, -1));
        countBackTracking(dp, 0, n, k, 0, target);
        return dp[0][0] % MOD;
    }
};
