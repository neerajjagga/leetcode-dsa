class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int maxLen = 0;
        int l = 0;

        for(int r=0; r<nums.size(); r++) {
            s.insert(nums[r]);

            while(*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[l]));
                l++;
            }

            int length = r - l + 1;
            maxLen = max(maxLen, length);
        }

        return maxLen;
    }
};