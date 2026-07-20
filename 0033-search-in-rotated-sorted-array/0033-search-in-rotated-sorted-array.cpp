class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;
            
            // find sorted half array
            // know if first half is sorted or not
            // it means first half is sorted
            if(nums[low] <= nums[mid]) {
                // now try to find the target in sorted half
                if(nums[low] <= target && target <= nums[mid])
                    high = mid - 1;

                // if not then go to unsorted half
                else low = mid + 1;
            }
            else {
                if(nums[mid] <= target && target <= nums[high])
                    low = mid + 1;
                else high = mid - 1;
            }
        }

        return -1;
    }
};