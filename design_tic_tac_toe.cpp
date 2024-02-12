// Link: https://leetcode.com/problems/design-tic-tac-toe/

class TicTacToe {
    vector<vector<char> > mat;
    int n;
    
    int get_winner() {
        bool rowfound = false;
        bool diaga1 = true, diagb1 = true;
        bool diaga2 = true, diagb2 = true;
        bool diaga3 = true, diagb3 = true;
        bool diaga4 = true, diagb4 = true;
        for (int i = 0; i < n; ++i) {
            bool rowa = true, rowb = true;
            for (int j = 0; j < n; ++j && (rowa || rowb)) {
                if (mat[i][j] != 'x') {
                    rowa = false;
                }
                if (mat[i][j] != 'o') {
                    rowb = false;
                }
            }
            if (rowa) {
                return 1;
            }
            if (rowb) {
                return 2;
            }
            bool cola = true, colb = true;
            for (int j = 0; j < n; ++j && (rowa || rowb)) {
                if (mat[j][i] != 'x') {
                    cola = false;
                }
                if (mat[j][i] != 'o') {
                    colb = false;
                }
            }
            if (cola) {
                return 1;
            }
            if (colb) {
                return 2;
            }
            if (mat[i][i] != 'x') {
                diaga1 = false;
            }
            if (mat[i][i] != 'o') {
                diagb1 = false;
            }
            if (mat[n-1-i][i] != 'x') {
                diaga2 = false;
            }
            if (mat[n-1-i][i] != 'o') {
                diagb2 = false;
            }
            if (mat[i][n-1-i] != 'x') {
                diaga3 = false;
            }
            if (mat[i][n-1-i] != 'o') {
                diagb3 = false;
            }
            if (mat[n-1-i][n-1-i] != 'x') {
                diaga4 = false;
            }
            if (mat[n-1-i][n-1-i] != 'o') {
                diagb4 = false;
            }
        }
        if (diaga1 || diaga2 || diaga3 || diaga4) {
            return 1;
        }
        if (diagb1 || diagb2 || diagb3 || diagb4) {
            return 2;
        }
        return 0;
    }

public:
    TicTacToe(int n) {
        this->n = n;
        mat = vector<vector<char> > (n, vector<char> (n, ' ')); 
    }
    
    int move(int row, int col, int player) {
        mat[row][col] = (player == 1) ? 'x' : 'o';
        return get_winner();
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
 