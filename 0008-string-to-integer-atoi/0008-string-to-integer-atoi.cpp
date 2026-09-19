class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        // skip zeroes
        while(i < n && s[i] == ' ')
            i++;
        
        // check sign
        bool negative = false;

        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-')
                negative = true;
            i++;
        }

        long long ans = 0;

        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if(ans > INT_MAX / 10 ||
            ans == INT_MAX / 10 && digit > 7)
                return negative ? INT_MIN : INT_MAX;
            
            ans = ans * 10 + digit;
            i++;
        }

        if(negative)
            ans = -ans;
        
        return ans;
    }
};