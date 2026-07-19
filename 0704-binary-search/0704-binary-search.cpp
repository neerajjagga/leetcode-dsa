class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, end = n-1;

        while(low <= end) {
            int mid = low + (end - low) / 2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }
};