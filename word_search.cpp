class Solution {

private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0,-1, 1};
    
public:
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited,
             int i, int j, string& word, int k) {
        if(k == (int)word.size()) return true;
        visited[i][j] = true;
        for(int l = 0; l < 4; ++l) {
            int x = i + dx[l];
            int y = j + dy[l];
            if(x < 0 || x >= board.size() || y < 0 
               || y >= board[0].size() || board[x][y] != word[k]
               || visited[x][y])     continue;
                if(dfs(board, visited, x, y, word, k+1)) {
                    return true;
                }
        }
        visited[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(board[i][j] == word[0]) {
                    if(word.size() == 1)    return true;
                    vector<vector<bool>> visited(n,vector<bool>(m,false));
                    visited[i][j] = true;
                    if(dfs(board, visited, i, j, word, 1))  return true;
                }
            }
        }
        return false;
    }
};
