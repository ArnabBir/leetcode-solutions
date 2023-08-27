// Link : https://leetcode.com/problems/maximize-value-of-function-in-a-ball-passing-game

class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        if (n == 1) {
            return receiver[0]*k;
        }
        vector<vector<int>> next(n, vector<int>(40,0));
        vector<vector<long long>> score(n, vector<long long>(40,0));
        for (int i = 0; i < n; ++i) {
            next[i][0] = receiver[i];
            score[i][0] = receiver[i];
        }
        for (int j = 1; j < 40; ++j) {
            for (int i = 0; i < n; ++i) {
                next[i][j] = next[next[i][j-1]][j-1];
                score[i][j] = score[i][j-1] + score[next[i][j-1]][j-1];
            }
        }
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            long long curr = i;
            long long pos = i;
            for (int j = 0; j < 40; ++j) {
                if (k & (1LL<<j)) {
                    curr += score[pos][j];
                    pos = next[pos][j];
                }
            }
            result = max(result, curr);
        }
        return result;
    }
};