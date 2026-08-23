class Solution {
public:
    int funct(vector<int> &prefixSum, int L, int M) {
        int n = prefixSum.size();

        int result = 0; // max overall sum
        int maxLBlockSum = 0;

        for(int mEnd=L+M-1; mEnd<n; mEnd++) {
            int lEnd = mEnd - M;
            int lStartPrevIndex = lEnd - L;

            int mBlockSum = prefixSum[mEnd] - prefixSum[lEnd];
            int lBlockSum = prefixSum[lEnd] - (lStartPrevIndex < 0 ? 0 : prefixSum[lStartPrevIndex]);

            maxLBlockSum = max(maxLBlockSum, lBlockSum);

            result = max(result, maxLBlockSum + mBlockSum);
        }

        return result;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n = nums.size();

        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        return max(funct(prefixSum, L, M), funct(prefixSum, M, L));
    }
};