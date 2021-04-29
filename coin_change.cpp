class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX);
        dp[amount] = 0;
        set<int> s;
        s.insert(amount);
        sort(coins.begin(), coins.end());
        for(int i = n-1; i >= 0; --i) {
            for(set<int>::reverse_iterator itr = s.rbegin(); itr != s.rend(); ++itr) {
                int j = *itr;
                int idx = j-coins[i];
                if(idx >= 0) {
                    dp[idx] = min(dp[idx], dp[j]+1);
                    s.insert(idx);
                }
            }
        }
        return (dp[0] == INT_MAX) ? -1 : dp[0];
    }
};
