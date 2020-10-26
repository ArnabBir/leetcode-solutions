class Solution {
public:
    
    vector<vector<int>> combos;
    
    void combinationSum2Util(vector<int>& candidates, int target, vector<int> &combo, int x) {
        if(target == 0) {
            combos.push_back(combo);
            return;
        }
        for(int i = x; i < candidates.size(); ++i) {
            if(candidates[i] > target)  break;
            if(i > x && candidates[i] == candidates[i-1]) {
                continue;
            }
            combo.push_back(candidates[i]);
            combinationSum2Util(candidates, target - candidates[i], combo, i+1);
            combo.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combo; 
        sort(candidates.begin(), candidates.end());
        combinationSum2Util(candidates, target, combo, 0);
        return combos;
    }
};
