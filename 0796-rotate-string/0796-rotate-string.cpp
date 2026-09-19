class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        if(s == goal) return true;

        for(int i=1; i<s.length(); i++) {
           string rotated = s.substr(i) + s.substr(0, i);
           if(rotated == goal) return true;
        }
        return false;
    }
};