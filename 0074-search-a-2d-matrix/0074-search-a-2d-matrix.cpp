class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row*col;

        int low = 0, high = n-1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;

            int rowIndex = mid/col;
            int colIndex = mid%col;
            int currNum = matrix[rowIndex][colIndex];

            if(currNum == target) return true;
            else if(target > currNum) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};