class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, char> charMap;
        unordered_set<char> used;

        for(int i=0; i<s.length(); i++) {
            char original = s[i];
            char replacement = t[i];

            if(!charMap.count(original)) {
                if(used.count(replacement))
                    return false;
                charMap[original] = replacement;
                used.insert(replacement);
            }
            else {
                char mappedChar = charMap[original];
                if(mappedChar != replacement) return false; 
            }
        }

        return true;
    }
};