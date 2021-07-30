class Solution {
private:
    int count = 0;
    vector<vector<string>> ans;
public:
    
    void solveNQueensUtils(vector<string>& board, int x, int y, int n, int q) {
        if(x == n) {
            if(q == n){
                for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
                ans.push_back(board);
            }
            return;
        }
        bool place = true;
        if(board[x][y] == '.') {
            for(int i = 0; i < x; ++i) {
                if(board[i][y] == 'Q') {
                    place = false;
                    break;
                }
            }
            if(place) {
                for(int j = 0; j < y; ++j) {
                    if(board[x][j] == 'Q') {
                        place = false;
                        break;
                    }
                }
            }
            if(place) {
                int i = x, j = y;
                while(--i >= 0 && --j >= 0) {
                    if(board[i][j] == 'Q') {
                         place = false;
                        break;
                    }
                }
            }
            if(place) {
                int i = x, j = y;
                while(--i >= 0 && ++j < n) {
                    if(board[i][j] == 'Q') {
                         place = false;
                        break;
                    }
                }
            }
        }
        if(place) {
           board[x][y] = 'Q';
            ++q; 
            if(y < n-1) {
                solveNQueensUtils(board, x, y+1, n, q);
            }
            else {
                solveNQueensUtils(board, x+1, 0, n, q);
            }
            board[x][y] = '.';
            --q;
        }
        if(y < n-1) {
                solveNQueensUtils(board, x, y+1, n, q);
        }
        else {
            solveNQueensUtils(board, x+1, 0, n, q);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string row;
        for(int i = 0; i < n; ++i)  row += ".";
        vector<string> board(n,row);
        int q = 0;
        solveNQueensUtils(board, 0, 0, n, q);
        return ans;
    }
};
