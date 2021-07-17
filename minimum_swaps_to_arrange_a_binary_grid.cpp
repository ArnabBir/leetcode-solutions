class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n,0);
        for(int i = 0; i < n; ++i) {
            for(int j = n-1; j >= 0; --j) {
                if(grid[i][j] == 0) {
                    ++zeros[i];
                }
                else {
                    break;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            bool found = false;
            for(int j = i; j < n && !found; ++j) {
                if(zeros[j] >= (n-1-i)) {
                    found = true;
                    for(int k = j; k > i; --k) {
                        swap(zeros[k], zeros[k-1]);
                        ++ans;
                    }
                }
            }
            if(!found)  return -1;
        }
        return ans;
    }
};
