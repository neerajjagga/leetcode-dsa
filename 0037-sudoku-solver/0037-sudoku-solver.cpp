class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // check horizontaly
        for(int j=0; j<9; j++) {
            if(board[row][j] == dig)
                return false;
        }

        // check verticaly
        for(int r=0; r<9; r++) {
            if(board[r][col] == dig)
                return false;
        }

        /*
         - now we have to check in particular grid also
         - so if we are able to get the starting point of every grid, then we can check easily
        
        Starting points of every grids are:
            (0, 0), (0, 3), (0, 6)
            (3, 0), (3, 3), (3, 6)
            (6, 0), (6, 3), (6, 6)
        So here we can notice that, every digit is multiple of 3, so we can create some formula to calculate the stRow and stCol

        so stRow = (row/3)*3
        so stCol = (col/3)*3
        */

        int stRow = (row/3)*3;
        int stCol = (col/3)*3;

        for(int sr=stRow; sr<=stRow+2; sr++) {
            for(int sc=stCol; sc<=stCol+2; sc++) {
                if(board[sr][sc] == dig)
                    return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {
        // it means our sukudo is solved
        if(row == 9)
            return true;

        int nextRow = row;
        int nextCol = col+1;
        if(nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // if on current position a digit already exists, skip and check for next columns
        if(board[row][col] != '.')
            return helper(board, nextRow, nextCol);

        // check for every column
        for(char dig='1'; dig<='9'; dig++) {
            if(isSafe(board, row, col, dig)) {
                board[row][col] = dig;
                // then check for next col -. and if it gives true, means somewhere base case hit and our sukudo is solved
                if(helper(board, nextRow, nextCol))
                    return true;
                
                // backtracking
                board[row][col] = '.';
            }
        }

        // if wern't able to hit the base case, it means we are somewhere stuck, then backtrack
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};