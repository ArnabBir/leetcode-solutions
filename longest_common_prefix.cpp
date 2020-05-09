class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int x = 0;
        int j = 0;
        int minx = INT_MAX;
        int n = strs.size();
        if(n == 0)  return "";
        for(int i = 0; i < strs.size(); ++i) {
            minx = (minx <= strs[i].size()) ? minx : strs[i].size();
        }
        bool mismatch = false;
        int len = 0;
        for(int j = 0; j < minx; ++j) {
            for(int i = 1; i < n; ++i) {
                if(strs[0][j] != strs[i][j]) {
                    mismatch = true;
                    break;
                }
            }
            if(mismatch)    break;
            else ++len;
        }
        return strs[0].substr(0, len);
    }
};
