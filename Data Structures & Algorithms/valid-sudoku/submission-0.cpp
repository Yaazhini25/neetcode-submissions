class Solution {
public:
    bool isposs(vector<vector<char>>& board, int i, int j, char num){
        if(i<0 || j<0 || i>8 || j>8) return false;
        //checking the ith row
        for(int col=0; col<9; col++){
            if(board[i][col] == num  && (col!=j)) return false;
        }
        //checking the jth column
        for(int row=0; row<9; row++){
            if(board[row][j] == num  && (i!=row)) return false;
        }
        int  row = (i/3)*3, col = (j/3)*3;
        for(int r=row; r<row+3; r++){
            for(int c=col; c<col+3; c++){
                if(board[r][c] == num  && (r!=i && c!=j)) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(!isposs(board, i,j, board[i][j])) return false;
                }
            }
        }
        return true;
    }
};
