class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        int currentLen = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                currentLen++;
                maxLen = max(currentLen, maxLen);
            } 
            else currentLen = 0; 
        }

        return maxLen;
    }
};
