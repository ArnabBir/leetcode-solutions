class Solution {
public:
    bool row_check(int r,vector<vector<char>>& board){
        int arr[10]={0};
        for(int i=0;i<9;i++){
            if(board[r][i]!='.')
                arr[(int)(board[r][i]-'0')]++;
        }
        for(int i=0;i<10;i++)
            if(arr[i]>1)
                return false;
        return true;
    }
    bool col_check(int c,vector<vector<char>>& board){
        int arr[10]={0};
        for(int i=0;i<9;i++){
            if(board[i][c]!='.')
                arr[(int)(board[i][c]-'0')]++;
        }
        for(int i=0;i<10;i++)
            if(arr[i]>1)
                return false;
        return true;
    }
    bool block_check(int i,int j,vector<vector<char>>& board){
        int arr[10]={0};
        for(int a=i;a<i+3;a++){
            for(int b=j;b<j+3;b++){
                if(board[a][b]!='.')
                arr[(int)(board[a][b]-'0')]++;
            }
        }
        for(int i=0;i<10;i++)
            if(arr[i]>1)
                return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
            if(!row_check(i,board))
                return false;
         for(int i=0;i<9;i++)
            if(!col_check(i,board))
                return false;
        for(int i=0;i<9;i+=3)
            for(int j=0;j<9;j+=3)
                if(!block_check(i,j,board))
                    return false;
        return true;
    }
};
