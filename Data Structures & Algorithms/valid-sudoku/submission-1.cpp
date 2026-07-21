class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row, int col, char val){
        for(int i=0; i<9; i++){
            if(board[row][i] == val && (i!=col)) return false;
            if(board[i][col] == val && (i!=row)) return false;
        }
        int i=3*(row/3), j=3*(col/3);
        for(int a=i; a<i+3; a++){
            for(int b=j; b<j+3; b++){
                if(board[a][b] == val && (a!=row && b!=col)) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(!issafe(board,i,j,board[i][j])) return false;
                }
            }
        }
        return true;
    }
};
