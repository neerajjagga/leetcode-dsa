class Solution {
public:
    int funct(vector<int> &nums, int L, int M) {
        int n = nums.size();

        int lBlockSum = 0;
        int mBlockSum = 0;

        // precompute sum till L+M-1
        for(int i=0; i<=L+M-1; i++) {
            if(i < L) {
                lBlockSum += nums[i];
            } else {
                mBlockSum += nums[i];
            }
        }
        
        int result = mBlockSum + lBlockSum; // max overall sum
        int maxLBlockSum = lBlockSum;

        for(int mEnd=L+M; mEnd<n; mEnd++) {
            mBlockSum = mBlockSum + nums[mEnd] - nums[mEnd-M];
            lBlockSum = lBlockSum + nums[mEnd-M] - nums[mEnd-M-L];

            maxLBlockSum = max(maxLBlockSum, lBlockSum);

            result = max(result, maxLBlockSum + mBlockSum);
        }

        return result;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        return max(funct(nums, L, M), funct(nums, M, L));
    }
};