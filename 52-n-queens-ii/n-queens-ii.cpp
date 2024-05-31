class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperLeftDiagonalCheck;
    unordered_map<int, bool> bottomLeftDiagonalCheck;

    bool isSafe(int row, int col, vector<vector<char>> &board, int n){
        if(rowCheck[row] == true){
            return false;
        }
        if(upperLeftDiagonalCheck[col-row] == true){
            return false;
        }
        if(bottomLeftDiagonalCheck[row+col] == true){
            return false;
        }
        return true;
    }

    void solve(vector<vector<char>> &board, int col, int n, int &count){
        //Base case
        if(col >= n){
            count++;
            return;
        }

        // 1 case solve karna hai baki recursion sambhal lega
        for(int row = 0 ; row < n ; row++){
            if(isSafe(row, col, board, n)){
                // Rakh do
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagonalCheck[col-row] = true;
                bottomLeftDiagonalCheck[row+col] = true;

                //Recursive soln
                solve(board, col+1, n, count);
                
                // Backtrack
                board[row][col] = '.';
                rowCheck[row] = false;
                upperLeftDiagonalCheck[col-row] = false;
                bottomLeftDiagonalCheck[row+col] = false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n,'.'));
        int count = 0;
        int col = 0;
        solve(board, col, n, count);

        return count;
    }
};