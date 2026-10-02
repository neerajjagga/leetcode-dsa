class Solution {
public:
    int n, m;
    bool findWord(vector<vector<char>>& board, int i, int j, int idx, string& word) {
        if(idx == word.length())
            return true;

        // handle visited and outbounds
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '$')
            return false;

        // if current board[i][j] != word[idx]
        if(board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '$';

        // otherwise check all directions
        // UP
        if(findWord(board, i - 1, j, idx + 1, word))
            return true;

        // DOWN
        if(findWord(board, i + 1, j, idx + 1, word))
            return true;

        // LEFT
        if(findWord(board, i, j - 1, idx + 1, word))
            return true;

        // RIGHT
        if(findWord(board, i, j + 1, idx + 1, word))
            return true;

        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0] && findWord(board, i, j, 0, word))
                    return true;
            }
        }

        return false;
    }
};