class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(vector<string> &board, int row, int col, int n) {
        // check horizontally in same row
        for(int col=0; col<n; col++) {
            if(board[row][col] == 'Q')
                return false;
        }

        // check vertically in same row
        for(int r=0; r<n; r++) {
            if(board[r][col] == 'Q')
                return false;
        }

        // left diagonal
        for(int r=row, c=col; r>=0 && c>=0; r--,c--) {
            if(board[r][c] == 'Q')
                return false;
        }

        // right diagonal
        for(int r=row, c=col; r>=0 && c<n; r--,c++) {
            if(board[r][c] == 'Q')
                return false;
        }

        return true;
    }

    void NQueens(vector<string> &board, int row, int n) {
        // here means, in 0 - n-1 all the n queens are placed at safe place 
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col=0; col<n; col++) {
            // for every column in current row, find the safe place for queen
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                // then try to place next queen in next row
                NQueens(board, row+1, n);

                // backtracking - after placing queen in current safe place and exploring by choosing that safe place, make it empty and try other safe place
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        NQueens(board, 0, n);
        return ans;
    }
};