class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakpoint = -1;

        // first find the breakpoint
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                breakpoint = i;
                break;
            }
        }

        // if the breakpoint not found, then it means the nums are already max according to lexicographical order, then just return the reverse of that
        if(breakpoint == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find the next greater element according to breakpoint, most smallest in right according to breakpoint 
        for(int i=n-1; i>breakpoint; i--) {
            if(nums[i] > nums[breakpoint]) {
                swap(nums[i], nums[breakpoint]);
            }
        }

        // reverse the right part, because it is in decreasing order, to make the nearest next possible permuation reverse that to small the value
        reverse(nums.begin() + breakpoint + 1, nums.end());
        return; 
    }
};