class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> results;
        for(int i = 0; i <= rowIndex; ++i) {
            vector<int> result;
            result.push_back(1);
            for(int j = 1; j < i; ++j) {
                result.push_back(results[i-1][j-1] + results[i-1][j]);
            }
            if(i > 0)   result.push_back(1);
            results.push_back(result);
        }
        return results[rowIndex];
    }
};
