class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int minLen = INT_MAX;
        int sum = 0;

        for(int right=0; right<nums.size(); right++) {
            sum += nums[right];

            while(sum >= target) {
                int length = right - left + 1;
                minLen = min(minLen, length);

                sum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};