class Solution {

private:
    
    int count;

public:
    
    Solution() {
        count = 0;
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if(grid[i][j] == '0') {
            return;
        }
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        grid[i][j] = '0';
        while(!q.empty()) {
            pair<int, int> p = q.front();
            i = p.first;
            j = p.second;
            q.pop();
            if(i < m-1) {
                if(grid[i+1][j] == '1') {
                    q.push(make_pair(i+1,j));
                    grid[i+1][j] = '0';
                }
            }
            if(i > 0) {
                if(grid[i-1][j] == '1') {
                    q.push(make_pair(i-1,j));
                    grid[i-1][j] = '0';
                }
            }
            if(j > 0) {
                if(grid[i][j-1] == '1') {
                    q.push(make_pair(i,j-1));
                    grid[i][j-1] = '0';
                }
            }
            if(j < n-1) {
                if(grid[i][j+1] == '1') {
                    q.push(make_pair(i,j+1));
                    grid[i][j+1] = '0';
                }
            }
        }
        ++count;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            int j = 0;
            vector<char>::iterator itr;
            while((itr = find(grid[i].begin() + j, grid[i].end(), '1')) != grid[i].end()) {
                int j = itr - grid[i].begin();
                bfs(grid, i, j, m, n);
                ++j;
            }
        }
        return count;
    }
};
