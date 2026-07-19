class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // Better sol
        // Time - O(n × m)
        // Space - O(n + m)
        // int n = matrix.size();
        // int m = matrix[0].size();

        // vector<int> row(n , 0);
        // vector<int> col(m , 0);

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         if(matrix[i][j] == 0) {
        //             row[i] = 1;
        //             col[j] = 1;
        //         }
        //     }
        // }

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         if(row[i] || col[j]) {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }




        // Optimal Sol
        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = matrix[0][0];

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;

                    // special case for j = 0;
                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(matrix[i][j] != 0) {
                    if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // explictly handle row 0 and col 0
        // thought when will all the elements in col[0] will be zero - if matrix[0][0] is zero
        if(matrix[0][0] == 0) {
            for(int j=0; j<m; j++) matrix[0][j] = 0;
        }

        // same for row = 0
        if(col0 == 0) {
            for(int i=0; i<n; i++) matrix[i][0] = 0;
        }
    }
};