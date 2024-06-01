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

    bool solve(vector<vector<char>>& board){
        int n = board.size();

        for(int row =0; row<n ; row++){
            for(int col=0 ; col<n ; col++){
                if(board[row][col] == '.'){
                    for(char val = '1' ; val <= '9' ; val++){
                        if(isValid(val,row,col,board)){
                            board[row][col] = val;

                            bool aageSolPossible = solve(board);

                            if(aageSolPossible){
                                return true;
                            }
                            else{
                                //backtrack
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};