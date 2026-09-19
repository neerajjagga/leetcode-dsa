class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());
        
        // to iterate over the characters
        int i = 0;

        // used to capture a word and reverse them
        int l = 0, r = 0;

        while(i < n) {
            // copy s[i] to s[r] until i found a space
            while(i < n && s[i] != ' ') {
                s[r] = s[i];
                r++;
                i++;
            }

            // after moving s, if we found a word, then it means l will be less then r, if there is a word
            if(l < r) {
                reverse(s.begin()+l, s.begin()+r);
                s[r] = ' ';
                r++;
                l = r;
            }

            i++;
        }

        return s.substr(0, r-1);
    }
};