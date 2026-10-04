class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0; // child
    int j = 0; // cookie

    while (i < g.size() && j < s.size()) {

        if (s[j] >= g[i]) {
            // Cookie can satisfy this child
            i++;
            j++;
        }
        else {
            // Cookie is too small for this child
            j++;
        }
    }

    return i;
}
};