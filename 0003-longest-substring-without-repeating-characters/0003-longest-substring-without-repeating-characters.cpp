class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hashIndices[256];
        for(int i=0; i<256; i++)
            hashIndices[i] = -1;

        int l = 0, r = 0;
        int maxLen = 0;

        while(r < s.length()) {
            if(hashIndices[s[r]] != -1) {
                if(hashIndices[s[r]] >= l) {
                    l = hashIndices[s[r]] + 1;
                }
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);

            hashIndices[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};