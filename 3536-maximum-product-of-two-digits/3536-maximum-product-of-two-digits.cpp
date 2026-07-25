class Solution {
public:
    int maxProduct(int n) {
        int largest = 0, second_largest = 0;

        while(n) {
            int digit = n % 10;
            n /= 10;

            if(digit > largest) {
                second_largest = largest;
                largest = digit;
            }
            else if(digit > second_largest)
                second_largest = digit;
        }

        return largest * second_largest;
    }
};