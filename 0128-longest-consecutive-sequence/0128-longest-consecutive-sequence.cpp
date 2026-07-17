class Solution {
public:


    // Brute force

    // bool linearSearch(vector<int> &nums, int x) {
    //     for(int num: nums) {
    //         if(num == x) {
    //             return true;
    //             break;
    //         }
    //     }
    //     return false;
    // }

    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();
    //     int longest = 0;

    //     for(int i=0; i<n; i++) {
    //         int num = nums[i];
    //         int count = 1;

    //         while(linearSearch(nums, num+1) == true) {
    //             count++;
    //             num += 1;
    //         }

    //         longest = max(longest, count);
    //     }

    //     return longest;
    // }







    // Better 

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int longest = 0;
        int count = 0;
        int lastSmaller = INT_MIN;

        for(int i=0; i<n; i++) {
            if(nums[i] - 1 == lastSmaller) {
                count++;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller) {
                count = 1;
                lastSmaller = nums[i];
            }

            longest = max(longest, count);
        }

        return longest;
    }
};