class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        int ans = -1;

        if(x == 0) return 0;

        while(low <= high)  {
            long long mid = low + (high - low ) / 2;
            long long value = mid*mid;

            if(value == x) return mid;
            else if(value < x) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;            
        }

        return ans;
    }
};