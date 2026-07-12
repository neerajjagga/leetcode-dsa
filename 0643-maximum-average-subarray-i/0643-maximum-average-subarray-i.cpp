class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxAvg = INT_MIN;
        long long sum = 0;

        int l = 0;

        for(int r=0; r<n; r++) {
            sum += nums[r];
            int window = r-l+1;

            if(window == k) {
                double currentAvg = double(sum) / window;
                maxAvg = max(maxAvg, currentAvg);
                sum-=nums[l];
                l++;
            }
        }

        return maxAvg;
    }
};