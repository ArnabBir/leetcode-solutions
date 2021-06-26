class Solution {
public:
    
    bool solveSudokuUtil(vector<vector<char>>& board, int i, int j) {
        if(i == 9)    return true;
        if(board[i][j] == '.') {
                    vector<bool> posbs(10, true);
                    for(int k = 0; k < 9; ++k) {
                        if(board[i][k] != '.') { 
                            posbs[board[i][k]-'0'] = false;
                        }
                        if(board[k][j] != '.') {
                            posbs[board[k][j]-'0'] = false;
                        }
                    }
                    int l = i/3;
                    int h = j/3;
                    for(int k = 3*l; k < 3*l+3; ++k) {
                        for(int m = 3*h; m < 3*h+3; ++m) {
                            if(board[k][m] != '.') {
                                posbs[board[k][m]-'0'] = false;
                            }
                        }
                    }
                    for(int k = 1; k <= 9; ++k) {
                        if(posbs[k]) {
                            board[i][j] = k + '0';
                            if(j < 8) {
                               if(solveSudokuUtil(board, i, j+1)) {
                                   return true;
                               }
                            }
                            else if(i < 8) {
                                if(solveSudokuUtil(board, i+1, 0)) {
                                    return true;
                                }
                            }
                            else {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
        }
        else {
            if(j < 8) {
                if(solveSudokuUtil(board, i, j+1)) {
                    return true;
                }
            }
            else if(i < 8) {
                if(solveSudokuUtil(board, i+1, 0)) {
                    return true;
                }
            }
            else {
                    return true;
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuUtil(board, 0, 0);
    }
};
