class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int originalNum = x;
        long long reversedNum = 0;

        while(x) {
            int digit = x % 10;
            reversedNum = reversedNum*10 + digit;
            x /= 10;
        }

        return originalNum == reversedNum;
    }
};