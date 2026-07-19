class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
        Intuition
            1. first convert every row in col
            2. reverse every col
        */

        int n = matrix.size();
        int m = matrix[0].size();

        int colMid = m / 2;
        int lastSwappedColIndex = m - 1;

        for(int i=0; i<n; i++) {
            for(int j = i; j<m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++) {
            lastSwappedColIndex = m - 1;
            for(int j=0; j<colMid; j++) {
                swap(matrix[i][j], matrix[i][lastSwappedColIndex]);
                lastSwappedColIndex--;
            }
        }
    }
};