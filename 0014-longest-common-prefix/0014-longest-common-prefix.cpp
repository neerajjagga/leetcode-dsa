class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = "";

        for(int i=0; i<strs[0].length(); i++) {
            for(int j=0; j<n-1; j++) {
                if(strs[j][i] != strs[j+1][i]) return prefix;
            }
            prefix += strs[0][i];
        }

        return prefix;
    }
};