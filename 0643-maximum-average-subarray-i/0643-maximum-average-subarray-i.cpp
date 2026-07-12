class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxAvg = 0;
        long long sum = 0;

        int l = 0, r = k - 1;

        for(int i = 0; i <= r; i++) {
            sum += nums[i];
        }

        maxAvg = (double)sum / k;

        while(r < n - 1) {
            sum -= nums[l++];
            sum += nums[++r];

            double currentAvg = double(sum) / k;
            maxAvg = max(maxAvg, currentAvg);
        }

        return maxAvg;
    }
};