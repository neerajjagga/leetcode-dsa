class Solution {
public:
    // https://chatgpt.com/share/6a8aaf1b-0f68-83ee-81dc-5c92ddb73f17
    long long numOfSubsequences(string s) {
        int n = s.length();

        vector<long long> prefix(n+1, 0);
        vector<long long> suffix(n+1, 0);

        for(int i=0; i<n; i++) {
            if(s[i] == 'L') prefix[i+1] = 1;
            prefix[i+1] += prefix[i];
        }

        for(int i=n-1; i>=0; --i) {
            if(s[i] == 'T') suffix[i] = 1;
            suffix[i] += suffix[i+1];
        }

        long long p1 = 0;
        long long p2 = 0;
        long long p3 = 0;
        long long maxi = 0;

        /*
            For every existing C:

            Calculate its contribution if L is inserted
            Calculate its contribution if T is inserted
            Calculate its existing contribution
        */
        for(int i=0; i<n; i++) {
            if(s[i] == 'C') {
                p1 += (prefix[i+1] + 1) * suffix[i];
                p2 += (suffix[i] + 1) * prefix[i+1];
                p3 += prefix[i+1] * suffix[i];
            }
            maxi = max(maxi, prefix[i+1] * suffix[i]);
        }

        p3 += maxi;

        return max({ p1, p2, p3 });
    }
};