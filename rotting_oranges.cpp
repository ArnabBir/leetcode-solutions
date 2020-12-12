class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int t = 0;
        int count = 0, rotten = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] != 0) {
                    ++count;
                    if(grid[i][j] == 2) {
                        ++rotten;
                    }
                }
            }
        }
        while(rotten < count) {
            int inc = 0;
            vector<vector<int>> temp = grid;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(grid[i][j] == 2) {
                        if(i-1>=0) {
                            if(temp[i-1][j] == 1) {
                                temp[i-1][j] = 2;
                                ++rotten;
                                ++inc;
                            }
                        }
                        if(j-1>=0) {
                            if(temp[i][j-1] == 1) {
                                temp[i][j-1] = 2;
                                ++rotten;
                                ++inc;
                            }
                        }
                        if(i+1<n) {
                            if(temp[i+1][j] == 1) {
                                temp[i+1][j] = 2;
                                ++rotten;
                                ++inc;
                            }
                        }
                        if(j+1<m) {
                            if(temp[i][j+1] == 1) {
                                temp[i][j+1] = 2;
                                ++rotten;
                                ++inc;
                            }
                        }
                    }
                }
            }
            grid = temp;         
            if(inc == 0) {
                return -1;
            }
            else ++t;
            
        }
        return t;
    }
};
