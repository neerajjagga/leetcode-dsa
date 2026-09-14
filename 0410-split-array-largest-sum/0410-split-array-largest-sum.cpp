class Solution {
public:
    bool isPossible(vector<int> &nums, int k, long long maxSubSum) {
        long long currSubSum = 0;
        int partitions = 1;

        for(int num: nums) {
            if(currSubSum + num > maxSubSum) {
                partitions++;
                currSubSum = num;
            }
            else currSubSum += num; 
        }

        return partitions <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = -1;

        while(low <= high) {
            long long mid = (low + high) / 2;

            if(isPossible(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};
