class Solution {
public:
    vector<vector<string>> ans;

    bool isPalin(string s) {
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        return s == reversed;
    }

    void getAllParts(string s, vector<string>& partitions) {
        if(s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        for(int i=0; i<s.size(); i++) {
            string part = s.substr(0, i+1);
            if(isPalin(part)) {
                partitions.push_back(part);
                getAllParts(s.substr(i+1), partitions);

                // backtrack
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        getAllParts(s, partitions);
        return ans;
    }
};