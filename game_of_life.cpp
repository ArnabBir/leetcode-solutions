class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] = {1,-1, 0, 0, 1, 1,-1,-1};
        int dy[] = {0, 0, 1,-1, 1,-1, 1,-1};
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int count = 0;
                for(int k = 0; k < 8; ++k) {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(x >= 0 && y >= 0 && x < m && y < n) {
                        if(board[x][y] > 0) {
                            ++count;
                        }
                    }
                }
                if(count < 2 && board[i][j] == 1) {
                        board[i][j] = 2;
                    }
                    else if(count > 3 && board[i][j] == 1) {
                        board[i][j] = 2;
                    }
                    else if(count == 3 && board[i][j] == 0) {
                        board[i][j] = -2;
                    }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 2) {
                    board[i][j] = 0;
                }
                else if(board[i][j] == -2) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
