class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<vector<int>>> dp(target+1);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < target; ++j) {
                if(j != 0) {
                    if(dp[j].size() == 0) {
                        continue;
                    }
                }
                if(j + candidates[i] <= target) {
                    vector<vector<int>> v = dp[j];
                    if(v.size() == 0) {
                        vector<int> temp;
                        temp.push_back(candidates[i]);
                        dp[j+candidates[i]].push_back(temp);
                    }
                    else {
                        for(int k = 0; k < v.size(); ++k) {
                            v[k].push_back(candidates[i]);
                            dp[j+candidates[i]].push_back(v[k]);
                        }
                    }
                }
            }
        }
        return dp[target];
    }
};
