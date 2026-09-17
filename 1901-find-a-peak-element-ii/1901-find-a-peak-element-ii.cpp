class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            int maxRow = 0;

            for(int currRow=0; currRow<n; currRow++) {
                if(mat[currRow][mid] > mat[maxRow][mid])
                    maxRow = currRow;
            }

            int left = (mid-1 >= 0) ? mat[maxRow][mid-1] : -1;
            int right = (mid+1 < m) ? mat[maxRow][mid+1] : -1;

            int current = mat[maxRow][mid];

            if(current > left && current > right)
                return {maxRow, mid};
            
            if(left > current)
                high = mid - 1;
            else low = mid + 1;
        }

        return {-1, -1};
    }
};