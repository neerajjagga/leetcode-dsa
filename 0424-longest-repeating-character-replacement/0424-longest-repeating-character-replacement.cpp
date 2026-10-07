class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxLen = 0, maxFreq = 0;
        
        vector<int> hash(26, 0);

        while(r < s.length()) {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            int len = r-l+1;
            if(len - maxFreq > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            if(len - maxFreq <= k) {
                maxLen = max(maxLen, len);
            }
            r++;
        }

        return maxLen;
    }
};