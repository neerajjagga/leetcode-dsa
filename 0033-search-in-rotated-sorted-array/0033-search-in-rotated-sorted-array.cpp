class Solution {
public:
    int findPivotIndex(vector<int>& nums) {
        int n = nums.size();

        // array is already sorted
        if (nums[0] <= nums[n - 1])
            return n - 1;

        int low = 0, end = n-1;

        while(low <= end) {
            if(low == end) return low;

            int mid = low + (end - low) / 2;

            if(mid-1 >= 0 && nums[mid] < nums[mid - 1]) return mid - 1;
            else if(mid+1 < n && nums[mid] > nums[mid+1]) return mid;
            else if(nums[low] > nums[mid]) end = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    int binarySearch(vector<int>& nums, int low, int end, int target) {
        while(low <= end) {
            int mid = low + (end - low) / 2;
            
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else end = mid - 1; 
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivotIndex(nums);
        
        int ans  = -1;

        // search in A
        if(target >= nums[0] && target <= nums[pivotIndex]) {
            ans = binarySearch(nums, 0, pivotIndex, target);
        }
        else { 
            // search in B
            ans = binarySearch(nums, pivotIndex+1, nums.size() - 1, target);
        }
        return ans;
    }
};