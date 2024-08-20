class Solution {
public:
    bool isValid(char value, int row, int col, vector<vector<char>>& board){
        for(int i=0 ; i<9; i++){
            //Row Check
            if(board[row][i] == value){
                return false;
            }
            //col Check
            if(board[i][col] == value){
                return false;
            }
            // 3*3 matrix check
            if(board[3*(row/3) +(i/3)][3*(col/3) +(i%3)] == value){
                return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row =0; row<9 ; row++){
            for(int col=0 ; col<9 ; col++){
                char ch = board[row][col];
                board[row][col] = '.';
                if(ch != '.' && !isValid(ch, row, col, board)){
                    board[row][col] = ch;
                    return false;
                }
                board[row][col] = ch;
            }
        }
        return true;
    }
};